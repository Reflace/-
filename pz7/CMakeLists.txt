cmake_minimum_required(VERSION 3.16)

project(pz7)

enable_testing()

add_subdirectory(test)

add_executable(${PROJECT_NAME} main.cpp)