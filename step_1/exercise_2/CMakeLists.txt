#Any project's top most CMakeLists.txt must start by specifying a minmimum CMake version.
cmake_minimum_required(VERSION 3.10)
#Used to start a project and set its name.
project(exercise2)

#Example of special variables that can be set within a CMake script for a project.
#In this case the variables "CMAKE_CXX_STANDARD" and "CMAKE_CXX_STANDARD_REQUIRED" are passed to set().
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Tells CMake to create an executable using the specified source code files
add_executable(Tutorial tutorial.cxx)