# Virtual Memory Simulator

A simulator for virtual memory management that demonstrates page tables, page faults, and various page replacement algorithms.

## Project Goals

- Build a custom memory allocator and frame management system
- Implement virtual-to-physical address translation
- Simulate page faults and page replacement policies
- Compare different replacement algorithms:
  - FIFO (First-In-First-Out)
  - LRU (Least Recently Used)
  - Optimal (theoretical best-case)
- Visualize memory access patterns and page faults

## Learning Focus

- Memory management fundamentals
- Page replacement algorithms
- Raw pointer manipulation in C++
- Performance analysis and algorithm comparison
- Data structure design for efficient lookups

## Getting Started

### Prerequisites

- C++17 compatible compiler (g++ or clang++)
- CMake (3.14 or newer)

### Building the Project

```bash
mkdir build && cd build
cmake ..
make
```

### Running the Simulator

```bash
./memory_sim [algorithm] [page_count] [frame_count] [access_pattern_file]
```

## Project Structure

```
memory_simulator/
├── include/                      # Header files
│   ├── memory_manager.hpp        # Memory management core
│   ├── page_table.hpp            # Page table implementation
│   ├── replacement_algorithms.hpp # Replacement policy implementations
│   └── simulator.hpp             # Simulation controller
├── src/                          # Source files
│   ├── main.cpp                  # Entry point
│   ├── memory_manager.cpp        # Memory management implementation
│   ├── page_table.cpp            # Page table implementation
│   ├── replacement_algorithms.cpp # Replacement algorithms implementation
│   └── simulator.cpp             # Simulation controller implementation
├── tests/                        # Unit tests
├── data/                         # Sample memory access patterns
├── CMakeLists.txt                # CMake build configuration
└── README.md                     # This file
```

## Implementation Plan

1. Create a `MemoryManager` class to handle physical memory frames
2. Implement a `PageTable` for virtual-to-physical address mapping
3. Build replacement algorithm implementations (FIFO, LRU, Optimal)
4. Create a simulation controller to run and compare algorithms
5. Add visualization of page faults and memory access patterns
6. Implement comprehensive statistics collection and reporting

## Algorithms to Implement

1. **FIFO (First-In-First-Out)**
   - Replace the page that has been in memory the longest

2. **LRU (Least Recently Used)**
   - Replace the page that hasn't been accessed for the longest time
   - Requires tracking access history

3. **Optimal**
   - Replace the page that won't be used for the longest time in the future
   - Requires knowing future access patterns (theoretical benchmark)

## Resources

- [Operating System Concepts, 10th Edition](https://www.os-book.com/OS10/)
- [C++ Memory Management](https://en.cppreference.com/w/cpp/memory)
- [Page Replacement Algorithms](https://www.geeksforgeeks.org/page-replacement-algorithms-in-operating-systems/)
- [Virtual Memory in Operating Systems](https://www.tutorialspoint.com/operating_system/os_virtual_memory.htm)
