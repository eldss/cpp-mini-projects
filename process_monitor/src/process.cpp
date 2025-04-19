#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/process.h"

namespace fs = std::filesystem;

const fs::path Process::PROC_ROOT{"/path"};
const fs::path Process::COMMAND_NAME{"comm"};

Process::Process(int32_t pid)
    : m_pid{pid},
      m_memory_kb{0},
      m_cpu_usage{0.0},
      m_memory_usage{0.0},
      m_name{"Unknown"},
      m_user{"Unknown"},
      m_state{"Unknown"} {
    updateInfo();
}

Process::Status Process::updateInfo() {
    readProcessName();
    readProcessState();
    readMemoryUsage();
    readUserInfo();
    calculateCpuUsage();
}

Process::Status Process::readProcessName() {
    fs::path commPath = PROC_ROOT / std::to_string(m_pid) / COMMAND_NAME;

    std::error_code ec;
    if (!fs::exists(commPath, ec) || ec) {
        std::cerr << "Process comm file does not exist for PID" << m_pid << "\n";
        return Process::Status::FILE_NOT_FOUND;
    }

    std::ifstream commFile(commPath);
    if (!commFile) {
        std::cerr << "Failed to open comm file for PID" << m_pid << "\n";
        return Process::Status::FILE_NOT_READABLE;
    }

    std::string name;
    if (!std::getline(commFile, name)) {
        std::cerr << "Failed to read comm file for PID" << m_pid << "\n";
        return Process::Status::READ_ERROR;
    }

    if (!name.empty() && name.back() == '\n') {
        name.pop_back();
    }

    if (name.empty()) {
        std::cerr << "Comm file for PID" << m_pid << " is empty\n";
        return Process::Status::EMPTY_NAME;
    }

    m_name = std::move(name);
    return Process::Status::OK;
}

Process::Status Process::readProcessState() {}

Process::Status Process::readMemoryUsage() {}

Process::Status Process::readUserInfo() {}

Process::Status Process::calculateCpuUsage() {}