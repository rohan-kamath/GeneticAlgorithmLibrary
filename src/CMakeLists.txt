include_directories(${softdev_includes})

set(source_files main.cxx GeneticAlgorithm.cxx GAGenome.cxx GABinaryGenome.cxx)

add_executable(../softdev ${source_files})

target_link_libraries(softdev ${softdev_libs})

install(TARGETS ../softdev DESTINATION bin)

