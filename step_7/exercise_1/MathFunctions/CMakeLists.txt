#MathFunction as a library
add_library(MathFunctions MathFunctions.cxx)

#Include CheckCXXSourceCompilesModule
 include(CheckCXXSourceCompiles)

#Check whether log() and exp() exists in the target system
 check_cxx_source_compiles("
    #include <cmath>
    int main() {
      std::log(1.0);
      return 0;
    }
  " HAVE_LOG)
 
  check_cxx_source_compiles("
    #include <cmath>
    int main() {
      std::exp(1.0);
      return 0;
    }
  " HAVE_EXP)


#USE_MYMATH variable
option(USE_MYMATH "Use tutorial custom nath function definitions" ON)

#Conditional compilation based on USE_MYMATH variable
if (USE_MYMATH)

  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )

                if(HAVE_LOG AND HAVE_EXP)
    target_compile_definitions(SqrtLibrary
                               PRIVATE "HAVE_LOG" "HAVE_EXP"
                               )
  endif()

#Add our custom library to link to
target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
target_link_libraries(MathFunctions PUBLIC SqrtLibrary)


endif()


#Consumer must include current directory
target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

#Installation
set(installable_libs MathFunctions tutorial_compiler_flags)
if(TARGET SqrtLibrary)
    list(APPEND installable_libs SqrtLibrary)
endif()
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)