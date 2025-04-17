cmake_minimum_required(VERSION 3.14)

# Use FetchContent to download Catch2 (a popular C++ testing framework)
include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0  # Use a specific version
)
FetchContent_MakeAvailable(catch2)

# Add test executable
add_executable(thread_pool_tests 
    test_main.cpp
    thread_pool_tests.cpp
)

# Link with Catch2 and thread_pool library
target_link_libraries(thread_pool_tests PRIVATE 
    Catch2::Catch2WithMain
    thread_pool
)

# Link with pthread on Unix-like systems
if(UNIX)
    find_package(Threads REQUIRED)
    target_link_libraries(thread_pool_tests PRIVATE Threads::Threads)
endif()

# Register tests with CTest
include(CTest)
include(Catch)
catch_discover_tests(thread_pool_tests)
