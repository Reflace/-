#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class Parallelepiped {
private: 
    double a;
    double b;
    double c;
public:
    Parallelepiped(): a(0), b(0), c(0) {}
    Parallelepiped(double, double, double);

    inline double getA() const { return this->a; }
    inline double getB() const { return this->b; }
    inline double getC() const { return this->c; }
    inline double getVolume() const { return this->a * this->b * this->c; }

    inline void setA(double a) { this->a = a; }
    inline void setB(double b) { this->b = b; }
    inline void setC(double c) { this->c = c; }

    friend bool operator==(Parallelepiped, Parallelepiped);
    friend bool operator!=(Parallelepiped, Parallelepiped);
    friend bool operator>(Parallelepiped, Parallelepiped);
    friend bool operator<(Parallelepiped, Parallelepiped);

    friend ostream& operator<<(ostream& stream, const Parallelepiped& obj);
    friend istream& operator>>(istream& stream, Parallelepiped& obj);
};