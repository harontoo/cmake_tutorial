#MathFunction as a library
add_library(MathFunctions MathFunctions.cxx)

#USE_MYMATH variable
option(USE_MYMATH "Use tutorial custom nath function definitions" ON)

#Conditional compilation based on USE_MYMATH variable
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )
#Add our custom library to link to
target_link_libraries(MathFunctions PUBLIC SqrtLibrary)
endif()


