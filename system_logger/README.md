# System Resource Logger

A time-series logger for system-level resource statistics that tracks and records system performance metrics over time.

## Project Goals

- Track system resources including:
  - CPU utilization (overall and per-core)
  - Memory usage (total, free, cached)
  - Disk I/O statistics
- Log data to structured files (CSV or JSON format)
- Implement configurable sampling intervals
- Create a simple data visualization or reporting tool
- Practice time-based programming with `std::chrono`

## Learning Focus

- System resource monitoring APIs in Linux
- Time-series data collection and management
- File I/O for structured data formats
- Modern C++ time utilities (`std::chrono`)
- Optional: Multithreaded data collection

## Getting Started

### Prerequisites

- Docker and Docker Compose (for development environment)
- Or a Linux-based operating system (for direct access)
- C++17 compatible compiler (g++ or clang++)
- CMake (3.14 or newer)
- Optional: JSON library (e.g., nlohmann/json)

### Building the Project

#### Using Docker (Recommended)

The repository includes a Docker setup for consistent development:

```bash
# Start the Docker container
docker-compose up -d

# Build the project using the helper script
./docker-build.sh system_logger

# Run the program
docker-compose exec dev bash -c "cd /workspace/system_logger/build && ./logger"

# Run the tests
docker-compose exec dev bash -c "cd /workspace/system_logger/build && ctest"
# Or for more detailed test output:
docker-compose exec dev bash -c "cd /workspace/system_logger/build && ./tests/system_logger_tests"
```

#### Building Directly (Linux Only)

If you're on a Linux system and prefer to build directly:

```bash
mkdir build && cd build
cmake ..
make
```

### Running the Logger

```bash
./logger [interval_seconds] [output_file]
```

## Project Structure

```
system_logger/
├── include/                # Header files
│   ├── cpu_monitor.hpp     # CPU monitoring functionality
│   ├── memory_monitor.hpp  # Memory monitoring functionality
│   └── disk_monitor.hpp    # Disk I/O monitoring functionality
├── src/                    # Source files
│   ├── main.cpp            # Entry point
│   ├── cpu_monitor.cpp     # CPU monitoring implementation
│   ├── memory_monitor.cpp  # Memory monitoring implementation
│   └── disk_monitor.cpp    # Disk I/O monitoring implementation
├── tests/                  # Unit tests
├── CMakeLists.txt          # CMake build configuration
└── README.md               # This file
```

## Implementation Plan

1. Create monitor classes for each resource type (CPU, memory, disk)
2. Implement data collection from `/proc/stat`, `/proc/meminfo`, etc.
3. Design a logging system for CSV/JSON output
4. Add configurable sampling intervals using `std::chrono`
5. Optional: Implement a simple visualization tool or report generator

## Resources

- [Linux /proc filesystem documentation](https://man7.org/linux/man-pages/man5/proc.5.html)
- [C++17 chrono library](https://en.cppreference.com/w/cpp/chrono)
- [nlohmann/json library](https://github.com/nlohmann/json) (optional)
- [Linux System Programming, 2nd Edition](https://www.oreilly.com/library/view/linux-system-programming/9781449341527/)
