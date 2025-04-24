#pragma once

#include <cstdint>
#include <filesystem>
#include <string>

class Process {
   public:
    /**
     * Status codes for Process class
     */
    enum class Status { OK = 0, FILE_NOT_FOUND, FILE_NOT_READABLE, READ_ERROR };

    /**
     * Possible process states, per /stat file (https://man7.org/linux/man-pages/man5/proc_pid_stat.5.html), plus
     * Unknown
     */
    enum class State {
        RUNNING,
        SLEEPING,
        WAITING,
        ZOMBIE,
        STOPPED,
        TRACING,
        DEAD,
        WAKE_KILL,
        WAKING,
        PARKED,
        IDLE,
        UNKNOWN,
    };

    /**
     * Creates a new process object
     * @param pid Process ID
     */
    explicit Process(int32_t pid);

    /**
     * Updates all process information from proc
     * @return Status code indicating success or failure
     */
    Status updateInfo();

    // Getters
    int32_t            getPid() const { return m_pid; }
    const std::string& getName() const { return m_name; }
    double             getCpuUsage() const { return m_cpu_usage; }
    double             getMemoryUsage() const { return m_memory_usage; }
    int64_t            getMemoryKb() const { return m_memory_kb; }
    const std::string& getUser() const { return m_user; }
    const State        getState() const { return m_state; }

    // For testing purposes
    static void setProcRoot(const std::filesystem::path& path) { PROC_ROOT = path; }

   private:
    // Changed from const to allow modification for testing
    static std::filesystem::path       PROC_ROOT;
    static const std::filesystem::path COMMAND_NAME;
    static const std::filesystem::path STATISTICS;

    /// @brief Process ID
    int32_t m_pid;

    /// @brief Process Name
    std::string m_name;

    /// @brief CPU Usage of the process
    double m_cpu_usage;

    /// @brief Memory usage of the process
    double m_memory_usage;

    /// @brief Memory usage in KB
    int64_t m_memory_kb;

    /// @brief User of process
    std::string m_user;

    /// @brief State of process
    State m_state;

    // I could probably get everything from /stat but for the sake of learning, I'll be getting each of these from
    // separate individual proc/[id] files.
    Status readProcessName();
    Status readProcessState();
    Status readMemoryUsage();
    Status readUserInfo();
    Status calculateCpuUsage();
    Status readLineFromProc(int32_t pid, std::filesystem::path subdir, std::string& output);
};