#pragma once

#define _USE_MATH_DEFINES

#include "Parallelepiped.hpp"

class Predicate {
public:
    bool operator()(int a, int b) {
        return a < b;
    }
    bool operator()(double a, double b) {
        return a < b;
    }
    bool operator()(Parallelepiped p1, Parallelepiped p2) {
        return p1.getVolume() > p2.getVolume();
    }
};