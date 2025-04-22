#include <catch2/catch_all.hpp>
#include <filesystem>
#include <fstream>

#include "../include/process.h"

// Create a test fixture for Process tests
class ProcessTestFixture {
   public:
    ProcessTestFixture() { setupMockProcFs(); }

    ~ProcessTestFixture() { teardownMockProcFs(); }

   protected:
    std::filesystem::path m_mockProcDir;

    // Create a temporary directory structure that mimics /proc
    void setupMockProcFs() {
        // Create a temporary directory for our mock /proc
        m_mockProcDir = std::filesystem::temp_directory_path() / "mock_proc";
        std::filesystem::create_directories(m_mockProcDir);

        // Create a directory for our test process
        std::filesystem::create_directories(m_mockProcDir / "12345");

        // Create a comm file with a test process name
        std::ofstream commFile(m_mockProcDir / "12345" / "comm");
        commFile << "test_process" << std::endl;
        commFile.close();

        // Set the Process class to use our mock directory
        Process::setProcRoot(m_mockProcDir);
    }

    void teardownMockProcFs() {
        std::filesystem::remove_all(m_mockProcDir);
        // Reset the proc root to default
        Process::setProcRoot("/proc");
    }
};

// Test the Process constructor and readProcessName function
TEST_CASE_METHOD(ProcessTestFixture, "Process name is read correctly", "[process]") {
    // Create a Process object with our test PID
    Process process(12345);

    // Check that the name was read correctly
    REQUIRE(process.getName() == "test_process");
}

// Test handling of non-existent process
TEST_CASE_METHOD(ProcessTestFixture, "Non-existent process returns FILE_NOT_FOUND", "[process]") {
    // Create a Process object with a non-existent PID
    Process process(99999);

    // Name should be "Unknown" since the file wasn't found
    REQUIRE(process.getName() == "Unknown");
}

// Test handling of empty process name
TEST_CASE_METHOD(ProcessTestFixture, "Empty process name returns EMPTY_NAME", "[process]") {
    // Create an empty comm file
    std::filesystem::create_directories(m_mockProcDir / "54321");
    std::ofstream commFile(m_mockProcDir / "54321" / "comm");
    commFile.close();

    // Create a Process object with our test PID
    Process process(54321);

    // Name should be "Unknown" since the file was empty
    REQUIRE(process.getName() == "Unknown");
}
