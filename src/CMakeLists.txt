include_directories(${softdev_includes})

set(source_files softdev.cxx GeneticAlgorithm.cxx Population.cxx Organism.cxx)

add_executable(../softdev ${source_files})

target_link_libraries(softdev ${softdev_libs})

install(TARGETS ../softdev DESTINATION bin)

