# Thread Pool Library

A general-purpose, reusable thread pool implementation in C++ for efficient task execution in multithreaded applications.

## Project Goals

- Create a thread pool that manages a collection of worker threads
- Implement a task queue for pending work items
- Use smart pointers for resource management
- Apply RAII principles for thread and synchronization primitives
- Support task priorities, cancellation, and future results
- Provide a clean, reusable API for client code

## Learning Focus

- Multithreading in modern C++
- Thread synchronization techniques
- Task-based parallelism
- Resource management with smart pointers
- RAII (Resource Acquisition Is Initialization) design pattern
- Template metaprogramming for generic tasks

## Getting Started

### Prerequisites

- Docker and Docker Compose (for development environment)
- Or a Linux-based operating system (for direct access)
- C++17 compatible compiler (g++ or clang++)
- CMake (3.14 or newer)
- POSIX threads library (pthread)

### Building the Project

#### Using Docker (Recommended)

The repository includes a Docker setup for consistent development:

```bash
# Start the Docker container
docker-compose up -d

# Build the project using the helper script
./docker-build.sh thread_pool

# Run the example program
docker-compose exec dev bash -c "cd /workspace/thread_pool/build && ./thread_pool_example"

# Run the tests
docker-compose exec dev bash -c "cd /workspace/thread_pool/build && ctest"
# Or for more detailed test output:
docker-compose exec dev bash -c "cd /workspace/thread_pool/build && ./tests/thread_pool_tests"
```

#### Building Directly (Linux Only)

If you're on a Linux system and prefer to build directly:

```bash
mkdir build && cd build
cmake ..
make
```

### Running the Example

```bash
./thread_pool_example
```

## Project Structure

```
thread_pool/
├── include/                    # Header files
│   ├── thread_pool.hpp         # Main thread pool implementation
│   ├── task.hpp                # Task abstraction
│   └── thread_safe_queue.hpp   # Thread-safe queue implementation
├── src/                        # Source files
│   └── main.cpp                # Example usage
├── tests/                      # Unit tests
├── CMakeLists.txt              # CMake build configuration
└── README.md                   # This file
```

## Implementation Plan

1. Create a thread-safe queue for pending tasks
2. Implement the core thread pool with worker threads
3. Add support for submitting tasks and getting futures
4. Implement task priorities and cancellation
5. Create comprehensive examples and documentation
6. Add unit tests for thread safety and correctness

## API Design (Preliminary)

```cpp
// Basic usage example
ThreadPool pool(4); // 4 worker threads
auto future = pool.submit([](){ return 42; });
int result = future.get(); // Wait for task and get result

// With task priority
auto future2 = pool.submit([]{ return expensive_calculation(); }, Priority::HIGH);
```

## Resources

- [C++17 Threading Library](https://en.cppreference.com/w/cpp/thread)
- [C++ Concurrency in Action, 2nd Edition](https://www.manning.com/books/c-plus-plus-concurrency-in-action-second-edition)
- [RAII Pattern](https://en.cppreference.com/w/cpp/language/raii)
- [Smart Pointers in C++](https://en.cppreference.com/w/cpp/memory)
