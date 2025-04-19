#include <iostream>

#include <unistd.h>  // For getpid()

#include "../include/process.h"

int main() {
    // Test with the current process
    Process current_process(getpid());

    std::cout << "Process ID: " << current_process.getPid() << std::endl;
    std::cout << "Process Name: " << current_process.getName() << std::endl;

    return 0;
}
