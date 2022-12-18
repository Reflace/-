# создание тестового файла и списка тестов
create_test_sourcelist (Tests
    CommonCppTests.cpp
    AddTest.cpp
    DelTest.cpp
    Op1Test.cpp
    Op2Test.cpp
    Op3Test.cpp
    Op4Test.cpp
)

add_executable(CommonCppTests ${Tests})

target_include_directories(CommonCppTests PUBLIC ${CMAKE_BINARY_DIR}/)
target_link_directories(CommonCppTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}//)
target_link_libraries(CommonCppTests PUBLIC Setst)

include_directories(${CMAKE_BINARY_DIR}/)
include_directories(../)

set(TestsToRun ${Tests})
remove(TestsToRun CommonCppTests.cpp)

foreach(test ${TestsToRun})
    get_filename_component(TName ${test} NAME_WE)

    add_test(NAME ${TName} COMMAND CommonCppTests ${TName})
endforeach()