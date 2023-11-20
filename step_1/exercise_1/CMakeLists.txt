#Any project's top most CMakeLists.txt must start by specifying a minmimum CMake version
cmake_minimum_required(VERSION 3.10)
#Used to start a project and set its name
project(exercise1)
#Tells CMake to create an executable using the specified source code files
add_executable(Tutorial tutorial.cxx)
