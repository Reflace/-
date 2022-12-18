set(SOURCE1_LIB fun1.cpp fun.hpp)
set(SOURCE2_LIB fun2.cpp fun.hpp)
set(SOURCE3_LIB fun3.cpp fun.hpp)

add_library(Fun1 STATIC ${SOURCE1_LIB})
add_library(Fun2 STATIC ${SOURCE2_LIB})
add_library(Fun3 STATIC ${SOURCE3_LIB})