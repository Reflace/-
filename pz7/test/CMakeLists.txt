# создание тестового файла и списка тестов
create_test_sourcelist (Tests
    main_tst.cpp
    TestInt.cpp
    TestDbl.cpp
)

add_executable(main_tst ${Tests})

target_include_directories(main_tst PUBLIC ${CMAKE_BINARY_DIR})
target_link_directories(main_tst PUBLIC ${CMAKE_BINARY_DIR}/)

include_directories(${CMAKE_BINARY_DIR}/)
include_directories(../)

set(TestsToRun ${Tests})
remove(TestsToRun main_tst.cpp)

foreach(test ${TestsToRun})
    get_filename_component(TName ${test} NAME_WE)

    add_test(NAME ${TName} COMMAND main_tst ${TName})
endforeach()
