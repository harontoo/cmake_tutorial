#Any project's top most CMakeLists.txt must start by specifying a minmimum CMake version.
cmake_minimum_required(VERSION 3.10)
#Used to start a project and set its name.Added a version number for our project.
project(exercise1 VERSION 1.1)

#Example of special variables that can be set within a CMake script for a project.
#In this case the variables "CMAKE_CXX_STANDARD" and "CMAKE_CXX_STANDARD_REQUIRED" are passed to set().
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Adding a configuration file that contains our variables.
configure_file(TutorialConfig.h.in TutorialConfig.h)

#Add MathFunctions library
add_subdirectory(MathFunctions)


#Tells CMake to create an executable using the specified source code files.
add_executable(Tutorial tutorial.cxx)

#Link the new library to the final executable target
target_link_libraries(Tutorial PUBLIC MathFunctions  tutorial_compiler_flags)

#Specify where the target include files are located.
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )