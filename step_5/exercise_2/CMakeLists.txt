#Any project's top most CMakeLists.txt must start by specifying a minmimum CMake version.
cmake_minimum_required(VERSION 3.15)
#set compiler flags
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

#Used to start a project and set its name.Added a version number for our project.
project(exercise2 VERSION 1.1)


add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
#Tells CMake to create an executable using the specified source code files.
add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

#Adding a configuration file that contains our variables.
configure_file(TutorialConfig.h.in TutorialConfig.h)

#Add MathFunctions library
add_subdirectory(MathFunctions)



#Link the new library to the final executable target
target_link_libraries(Tutorial PUBLIC MathFunctions)

#Specify where the target include files are located.
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

#Installation
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)
