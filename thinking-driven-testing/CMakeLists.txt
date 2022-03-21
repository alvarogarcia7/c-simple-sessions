cmake_minimum_required(VERSION 3.5)

# Set the project name
project(project)

# Add an library for the example classes
add_library(prod_lib
        prod.c
        )


#############################################
# Unit tests

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(unit_tests
        munit.c
        test.c
        )
target_link_libraries(unit_tests
        prod_lib
        )

add_test(test_all
        unit_tests
        )
