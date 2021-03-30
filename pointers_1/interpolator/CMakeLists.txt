cmake_minimum_required(VERSION 3.5)

# Set the project name
project(project)

# Add an library for the example classes
add_library(interpolator_lib
        interpolate_template.c
        )

add_executable(interpolator
        main.c
        )
target_link_libraries(interpolator
        interpolator_lib
        )

