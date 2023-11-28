#add executable
add_executable(MakeTable MakeTable.cxx)

#add tutorial_compiler_flags to our executable
target_link_libraries(MakeTable PRIVATE tutorial_compiler_flags)

#add custom command
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
  )
