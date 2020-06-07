cmake_minimum_required(VERSION 3.5)

# Set the project name
project(project)

# Add an library for the example classes
add_library(prod_lib
        prod.c
        )


add_executable(prod
        main.c
        )
target_link_libraries(prod
        prod_lib
        )


#############################################
# Unit tests

# enable CTest testing
enable_testing()

# Include the header files
include_directories(${CMAKE_SOURCE_DIR}/vendor/cmocka/include)

find_library(cmocka
        NAMES libcmocka.so.0
        PATHS ${CMAKE_SOURCE_DIR}/vendor/cmocka)
message(STATUS "which library found?: ${cmocka}")
ADD_LIBRARY(cmocka SHARED IMPORTED)
SET_TARGET_PROPERTIES(cmocka PROPERTIES IMPORTED_LOCATION ${cmocka})
TARGET_LINK_LIBRARIES(${executable_name} cmocka)



# Add a testing executable
add_executable(unit_tests
        fizzBuzzTest.c
        )
target_link_libraries(unit_tests
        prod_lib
        cmocka
        )

add_test(test_all
        unit_tests
        )
