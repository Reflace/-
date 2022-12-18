cmake_minimum_required(VERSION 3.16)

project(pz4)

enable_testing()

add_subdirectory(tst)

add_executable(${PROJECT_NAME} main.cpp Parallelepiped.cpp)
