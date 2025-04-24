#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/process.h"
#include "process.h"

namespace fs = std::filesystem;

// For testing purposes, make this modifiable
fs::path       Process::PROC_ROOT{"/proc"};
const fs::path Process::COMMAND_NAME{"comm"};
const fs::path Process::STATISTICS{"stat"};

Process::Process(int32_t pid)
    : m_pid{pid},
      m_memory_kb{0},
      m_cpu_usage{0.0},
      m_memory_usage{0.0},
      m_name{"Unknown"},
      m_user{"Unknown"},
      m_state{Process::State::UNKNOWN} {
    updateInfo();
}

Process::Status Process::updateInfo() {
    Process::Status status = readProcessName();
    if (status != Process::Status::OK) {
        return status;
    }

    readProcessState();
    readMemoryUsage();
    readUserInfo();
    calculateCpuUsage();

    return Process::Status::OK;
}

Process::Status Process::readProcessName() {
    std::string     name;
    Process::Status res = Process::readLineFromProc(m_pid, COMMAND_NAME, name);
    if (res != Process::Status::OK) {
        return res;
    }

    if (!name.empty() && name.back() == '\n') {
        name.pop_back();
    }

    if (name.empty()) {
        // Keeps name as "Unknown"
        return Process::Status::OK;
    }

    m_name = std::move(name);
    return Process::Status::OK;
}

Process::Status Process::readProcessState() {
    std::string     stats;
    Process::Status res = Process::readLineFromProc(m_pid, STATISTICS, stats);
    if (res != Process::Status::OK) {
        return res;
    }

    // Skip to end of comm name to start tokenizing string
    size_t closeParensOfNameIdx = stats.find(')');
    // Add to to skip past space after ')'
    std::string post = stats.substr(closeParensOfNameIdx + 2);

    // Next val is state, see https://man7.org/linux/man-pages/man5/proc_pid_stat.5.html
    std::istringstream iss{post};
    std::string        token;
    for (int i = 0; i < 1; i++) {
        iss >> token;
    }

    using State = Process::State;

    // The file gives a single char for state
    char stateChar = token[0];
    switch (stateChar) {
        case 'R':
            m_state = State::RUNNING;
            break;
        case 'S':
            m_state = State::SLEEPING;
            break;
        case 'D':
            m_state = State::WAITING;
            break;
        case 'Z':
            m_state = State::ZOMBIE;
            break;
        case 'T':
            m_state = State::STOPPED;
            break;
        case 't':
            m_state = State::TRACING;
            break;
        case 'W':
            m_state = State::WAKING;
            break;
        case 'X':
            /* FALL THROUGH */
        case 'x':
            m_state = State::DEAD;
            break;
        case 'K':
            m_state = State::WAKE_KILL;
            break;
        case 'P':
            m_state = State::PARKED;
            break;
        case 'I':
            m_state = State::IDLE;
            break;
        default:
            // Keep unknown
            break;
    }
    return Process::Status::OK;
}

Process::Status Process::readMemoryUsage() {
    return Process::Status::OK;
}

Process::Status Process::readUserInfo() {
    return Process::Status::OK;
}

Process::Status Process::calculateCpuUsage() {
    return Process::Status::OK;
}

Process::Status Process::readLineFromProc(int32_t pid, fs::path subdir, std::string& output) {
    fs::path path = PROC_ROOT / std::to_string(pid) / subdir;

    std::error_code ec;
    if (!fs::exists(path, ec) || ec) {
        return Process::Status::FILE_NOT_FOUND;
    }

    std::ifstream statFile(path);
    if (!statFile) {
        return Process::Status::FILE_NOT_READABLE;
    }

    if (!std::getline(statFile, output)) {
        return Process::Status::READ_ERROR;
    }

    return Process::Status::OK;
}