add_subdirectory(parser)
add_subdirectory(ast)
add_subdirectory(codegen)

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
