# Per-Process Resource Sandbox

A utility for modifying scheduling parameters, CPU affinity, and niceness for any process ID (PID) on a Linux system.

## Project Goals

- Create a tool to modify process resource constraints:
  - CPU affinity (which cores a process can use)
  - Scheduling policy and priority
  - Process niceness (priority relative to other processes)
- Handle permissions and privilege escalation properly
- Implement an interactive CLI for real-time adjustments
- Optional: Support persistent configurations via config files

## Learning Focus

- Linux process scheduling and priority systems
- System calls for process control
- Permission handling and error management
- Command-line interface design
- Resource management in multi-process environments

## Getting Started

### Prerequisites

- Docker and Docker Compose (for development environment)
- Or a Linux-based operating system (for direct access)
- C++17 compatible compiler (g++ or clang++)
- CMake (3.14 or newer)
- Root/sudo access for modifying other processes

### Building the Project

#### Using Docker (Recommended)

The repository includes a Docker setup for consistent development:

```bash
# Start the Docker container
docker-compose up -d

# Build the project using the helper script
./docker-build.sh resource_sandbox

# Run the program
docker-compose exec dev bash -c "cd /workspace/resource_sandbox/build && ./sandbox"

# Run the tests
docker-compose exec dev bash -c "cd /workspace/resource_sandbox/build && ctest"
# Or for more detailed test output:
docker-compose exec dev bash -c "cd /workspace/resource_sandbox/build && ./tests/resource_sandbox_tests"
```

#### Building Directly (Linux Only)

If you're on a Linux system and prefer to build directly:

```bash
mkdir build && cd build
cmake ..
make
```

### Running the Sandbox

```bash
# For interactive mode
./sandbox

# For direct command mode
./sandbox --pid 1234 --nice 10 --affinity 0,1
```

## Project Structure

```
resource_sandbox/
├── include/                   # Header files
│   ├── process_controller.hpp # Process control functionality
│   ├── scheduler.hpp          # Scheduling policy management
│   └── cli.hpp                # Command-line interface
├── src/                       # Source files
│   ├── main.cpp               # Entry point
│   ├── process_controller.cpp # Process control implementation
│   ├── scheduler.cpp          # Scheduling policy implementation
│   └── cli.cpp                # CLI implementation
├── tests/                     # Unit tests
├── CMakeLists.txt             # CMake build configuration
└── README.md                  # This file
```

## Implementation Plan

1. Create a `ProcessController` class to wrap Linux syscalls
2. Implement functions for modifying CPU affinity, scheduling, and niceness
3. Build a command-line interface with interactive and direct modes
4. Add proper error handling and permission checking
5. Optional: Implement configuration file support for persistent settings

## Resources

- [Linux sched_setaffinity man page](https://man7.org/linux/man-pages/man2/sched_setaffinity.2.html)
- [Linux nice and setpriority man pages](https://man7.org/linux/man-pages/man2/setpriority.2.html)
- [Linux scheduling policies](https://man7.org/linux/man-pages/man7/sched.7.html)
- [C++17 Standard Library](https://en.cppreference.com/w/cpp/17)
- [Linux System Programming, 2nd Edition](https://www.oreilly.com/library/view/linux-system-programming/9781449341527/)
