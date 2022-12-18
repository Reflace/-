#pragma once

#define RADIUS 4.

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

/*
    Task1
    Going from left to right
    On the L edge fun1(x) will return -3 and on the R edge fun1(x) will return 3
*/

double fun1(double x);

/*
    Task2
    fun2(x, y) will return true if point M(x, y) is inside painted area, 
    radius of quarter of a circle is equal constant RADIUS
*/

bool fun2(double x, double y);