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
add_executable(memory_simulator_tests 
    test_main.cpp
    page_table_tests.cpp
    replacement_algorithm_tests.cpp
)

# Link with Catch2
target_link_libraries(memory_simulator_tests PRIVATE Catch2::Catch2WithMain)

# Register tests with CTest
include(CTest)
include(Catch)
catch_discover_tests(memory_simulator_tests)
