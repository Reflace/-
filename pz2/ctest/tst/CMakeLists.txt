# создание тестового файла и списка тестов
create_test_sourcelist (Tests
    maintst.cpp
    Tst1Insert.cpp
    Tst2Construct.cpp
    Tst3ConstructDef.cpp
    Tst4Del.cpp
    Tst5IsEmpty.cpp
    #Tst6Terminate.cpp
)

add_executable(maintst ${Tests})

include_directories(../src/)

set(TestsToRun ${Tests})
remove(TestsToRun maintst.cpp)

foreach(test ${TestsToRun})
    get_filename_component(TName ${test} NAME_WE)

    add_test(NAME ${TName} COMMAND maintst ${TName})
endforeach()
