# Process Monitor

A terminal-based monitor for active Linux processes, similar to a simplified version of `top` or `htop`.

## Project Goals

- Read from `/proc` filesystem to gather process information
- Display process details including:
  - PID (Process ID)
  - Command name
  - CPU usage percentage
  - Memory usage percentage
- Implement auto-refresh functionality (every N seconds)
- Practice object-oriented design in C++
- Learn Linux process management internals

## Learning Focus

- Linux `/proc` filesystem structure and usage
- Process information retrieval in Linux
- Terminal-based UI development
- Efficient parsing of system files
- Class design for maintainable code

## Getting Started

### Prerequisites

- Linux-based operating system (for `/proc` access)
- C++17 compatible compiler (g++ or clang++)
- CMake (3.14 or newer)
- Optional: ncurses library for advanced terminal UI

### Building the Project

```bash
mkdir build && cd build
cmake ..
make
```

### Running the Monitor

```bash
./monitor
```

## Project Structure

```
process_monitor/
├── include/           # Header files
│   └── process.hpp    # Process class definition
├── src/               # Source files
│   ├── main.cpp       # Entry point
│   └── process.cpp    # Process class implementation
├── tests/             # Unit tests
├── CMakeLists.txt     # CMake build configuration
└── README.md          # This file
```

## Implementation Plan

1. Create a `Process` class to represent individual processes
2. Implement functions to read from `/proc/[pid]/` directories
3. Calculate CPU and memory percentages
4. Build a simple terminal UI to display the information
5. Add refresh functionality with configurable intervals

## Resources

- [Linux Proc Filesystem Documentation](https://man7.org/linux/man-pages/man5/proc.5.html)
- [C++17 Standard Library](https://en.cppreference.com/w/cpp/17)
- [CMake Documentation](https://cmake.org/documentation/)
