cmake_minimum_required(VERSION 3.14)
project(process_monitor VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add include directory
include_directories(include)

# Add executable
add_executable(monitor 
    src/main.cpp
    src/process.cpp
)

# Link with filesystem library if needed
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_link_libraries(monitor stdc++fs)
endif()

# Optional: Add testing
option(BUILD_TESTS "Build the tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
