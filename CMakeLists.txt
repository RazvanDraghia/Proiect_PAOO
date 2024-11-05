# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name and specify the C++ standard
project(AutomobilProject VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the executable target and include the source files with the correct paths
add_executable(AutomobilApp src/main.cpp src/automobil.cpp)

# Specify include directories
target_include_directories(AutomobilApp PRIVATE include)

# Print a message for confirmation of successful configuration
message(STATUS "CMake configuration for AutomobilProject completed.")
