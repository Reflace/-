cmake_minimum_required(VERSION 3.22.1)

# set the project name
project(project)

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB Set.cpp)

#add_library(Setst STATIC ${SOURCE_LIB})
#add_library(Setsh SHARED ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include/gtest/)
target_link_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(main PUBLIC Setsh)

include_directories(${CMAKE_SOURCE_DIR}/)

add_executable(gtest1 test.cpp)
target_include_directories(gtest1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include/gtest/)
target_link_directories(gtest1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gtest1 PUBLIC Setsh gtest)

add_subdirectory(googletest)
include_directories(googletest)

enable_testing()
add_subdirectory(tst)