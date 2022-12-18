cmake_minimum_required(VERSION 3.22.1)

project(Pz2)

set(SOURCE_TEST_EXE test.cpp)

add_executable(run main.cpp)
target_include_directories(run PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_directories(run PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(run PUBLIC Fun1)

add_executable(test1 ${SOURCE_TEST_EXE})
add_executable(test2 ${SOURCE_TEST_EXE})
add_executable(test3 ${SOURCE_TEST_EXE})

target_include_directories(test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include/gtest/)
target_link_directories(test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test1 PUBLIC Fun1 gtest)

target_include_directories(test2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include/gtest/)
target_link_directories(test2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test2 PUBLIC Fun2 gtest)

target_include_directories(test3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include/gtest/)
target_link_directories(test3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test3 PUBLIC Fun3 gtest)

add_subdirectory(googletest)
include_directories(googletest)