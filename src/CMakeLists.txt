include_directories(${softdev_includes})

set(source_files softdev.cxx)

add_executable(../build/softdev ${source_files})

target_link_libraries(softdev ${softdev_libs})

install(TARGETS ../build/softdev DESTINATION bin)

