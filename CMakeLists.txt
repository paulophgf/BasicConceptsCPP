cmake_minimum_required(VERSION 3.20)
project(ModelProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(ModelProject
    main.cpp files/basic_operations.h files/vector_operations.h files/matrix_operation.h files/data_types.h)
