cmake_minimum_required(VERSION 3.5)

# Set the project name
project(project)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(prod
        main.c
        )
target_link_libraries(prod
       ${CONAN_LIBS}
        )
