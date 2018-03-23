cmake_minimum_required(VERSION 3.9)
project(Envision)

set(CMAKE_CXX_STANDARD 11)

set (HEADERS ${HEADERS}
        viewer.hpp)

set (SRC ${SOURCE_FILES}
        main.cpp
        read_facet.cpp
        initialize.cpp
        print_errors.cpp
        string_to_double.cpp read_facet_add.cpp add_area_to_cell.cpp)

add_executable(view ${SRC} ${HEADERS})

set_target_properties(view PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_HOME_DIRECTORY})
