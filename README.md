# C++ Mini Projects: Systems Programming Series

Welcome to the `cpp/mini-projects` collection — a curated series of C++ projects focused on operating systems, Linux internals, resource management, and performance-oriented programming. This collection serves as a practical, structured roadmap for deepening your understanding of C++17+ and systems-level development.

Each project is self-contained in its own subdirectory, but all share the same Git root for version control and GitHub publishing.

---

## Directory Structure
```
cpp/mini-projects/
├── process_monitor/       # Project 1
├── system_logger/         # Project 2
├── resource_sandbox/      # Project 3
├── thread_pool/           # Project 4
├── memory_simulator/      # Project 5
└── README.md              # Top-level plan & project summaries
```

---

## Learning Focus
This series emphasizes:
- Object-oriented design in C++
- Linux system programming APIs and internals
- Manual memory management and performance trade-offs
- Threading, scheduling, and inter-process resource handling
- Testable, modular code design using modern CMake

---

## Project Roadmap

### Project 1: Process Monitor
**Goal:** Terminal-based monitor for active Linux processes.
- Read from `/proc` to get PID, command, CPU%, MEM%
- Refresh every N seconds
- Emphasizes parsing, class design, and terminal output

### Project 2: System Resource Logger
**Goal:** Time-series logger of system-level resource stats.
- Track CPU, memory, disk I/O over time
- Log data to structured files (CSV/JSON)
- Use `std::chrono` and optionally multithreading

### Project 3: Per-Process Resource Sandbox
**Goal:** Modify scheduling/affinity/niceness for any PID.
- Wrap Linux syscalls for priority control
- Handle permissions, errors, and interactive CLI
- Optionally support persistent policies or config files

### Project 4: Thread Pool Library
**Goal:** Create a general-purpose, reusable thread pool.
- Task queue + worker threads
- Smart pointer resource control
- RAII-based locks and concurrency primitives

### Project 5: Virtual Memory Simulator
**Goal:** Simulate page tables, page faults, and replacement policies.
- Build your own allocator and memory frames
- Implement FIFO, LRU, Optimal algorithms
- Reinforce pointer management and algorithm design

---

## Timeline (Recommended)
| Week Range | Project                        | Key Focus                                 |
|------------|--------------------------------|-------------------------------------------|
| 1–1.5      | Process Monitor                | Linux internals, file parsing, OOP        |
| 1.5–2.5    | System Resource Logger         | IO patterns, logging, timers              |
| 2.5–3.5    | Resource Sandbox               | Syscalls, scheduling, process management  |
| 3.5–4.25   | Thread Pool Library            | Multithreading, queue design, concurrency |
| 4.25–5     | Virtual Memory Simulator       | Memory handling, algorithms, raw pointers |

---

## Tooling Setup
- Compiler: `g++` or `clang++` (C++17 or newer)
- Build System: `CMake`
- Debug Tools: `gdb`, `valgrind`, `perf`
- Optional Libraries:
  - `fmt` for formatting
  - `doctest` or `Catch2` for testing
  - `ncurses` for TUI

---

## How to Use
Each subdirectory contains:
- `CMakeLists.txt`
- `README.md` with project-specific goals
- `src/` and `include/` folders
- Optional: `tests/` folder for unit tests

To start a project:
```bash
cd cpp/mini-projects/process_monitor
mkdir build && cd build
cmake .. && make
./monitor
```