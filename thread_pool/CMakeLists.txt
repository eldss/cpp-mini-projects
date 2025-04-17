cmake_minimum_required(VERSION 3.14)
project(thread_pool VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add include directory
include_directories(include)

# Add library (header-only)
add_library(thread_pool INTERFACE)
target_include_directories(thread_pool INTERFACE include)

# Add example executable
add_executable(thread_pool_example src/main.cpp)
target_link_libraries(thread_pool_example PRIVATE thread_pool)

# Link with pthread on Unix-like systems
if(UNIX)
    find_package(Threads REQUIRED)
    target_link_libraries(thread_pool_example PRIVATE Threads::Threads)
endif()

# Optional: Add testing
option(BUILD_TESTS "Build the tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
