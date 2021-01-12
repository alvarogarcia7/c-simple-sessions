cmake_minimum_required(VERSION 3.5)

# Unit tests

# enable CTest testing
enable_testing()

# Include the header files
include_directories(${CMAKE_SOURCE_DIR}/vendor/cmocka/include)

find_library(cmocka
        NAMES libcmocka
        PATHS ${CMAKE_SOURCE_DIR}/vendor/cmocka)
message(STATUS "which library found?: ${cmocka}")
ADD_LIBRARY(cmocka SHARED IMPORTED)
SET_TARGET_PROPERTIES(cmocka PROPERTIES IMPORTED_LOCATION ${cmocka})
TARGET_LINK_LIBRARIES(${executable_name} cmocka)



# Add a testing executable
add_executable(unit_tests
        test.c
        )
target_link_libraries(unit_tests
        prod_lib
        cmocka
        )

add_test(test_all
        unit_tests
        )
