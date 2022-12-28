cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME heap)
set(SOURCE_CODE main.cpp Parallelepiped.cpp)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${SOURCE_CODE})

add_executable(Gtest test.cpp Parallelepiped.cpp)
target_include_directories(Gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include/gtest/)
target_link_directories(Gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Gtest PUBLIC gtest)

add_subdirectory(googletest)
include_directories(googletest)