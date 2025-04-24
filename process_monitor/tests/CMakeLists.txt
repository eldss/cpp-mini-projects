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
add_executable(process_monitor_tests 
    test_main.cpp
    test_process.cpp
)

# Add source files to test executable
target_sources(process_monitor_tests PRIVATE 
    ${CMAKE_SOURCE_DIR}/src/process.cpp
)

# Link with Catch2 and other libraries
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_link_libraries(process_monitor_tests PRIVATE Catch2::Catch2WithMain stdc++fs)
else()
    target_link_libraries(process_monitor_tests PRIVATE Catch2::Catch2WithMain)
endif()

# Register tests with CTest
include(CTest)
include(Catch)
catch_discover_tests(process_monitor_tests)
