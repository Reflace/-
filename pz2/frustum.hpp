#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class Frustum {
private:
    double h;
    double r1;
    double r2; 
public:
    Frustum();
    Frustum(double h, double r1, double r2);

    inline void setH(double h) { this->h = h; }
    inline void setR1(double r1) { this->r1 = r1; }
    inline void setR2(double r2) { this->r2 = r2; }

    double Volume();
    inline double getH() {return this->h; };
    inline double getR1() {return this->r1; };
    inline double getR2() {return this->r2; };

    friend bool operator == (Frustum f1, Frustum f2);
    friend bool operator != (Frustum f1, Frustum f2);
    friend bool operator > (Frustum f1, Frustum f2);
    friend bool operator < (Frustum f1, Frustum f2);
    friend ostream& operator<<(ostream& stream, const Frustum& obj);
    friend istream& operator>>(istream& stream, Frustum& obj);
};