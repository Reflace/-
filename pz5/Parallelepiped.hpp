// а) класс прямоугольный параллелепипед (элементы-данные: длины трёх рёбер, имеющих общую вершину);
// б) сравниваются объёмы параллелепипедов.

#pragma once

#include <iostream>

using namespace std;

class Parallelepiped {
private: 
    double a;
    double b;
    double c;
public:
    Parallelepiped(): a(0), b(0), c(0) {}
    Parallelepiped(double, double, double);

    //[[nodiscard]] спросить зачем
    inline double getA() const { return this->a; }
    inline double getB() const { return this->b; }
    inline double getC() const { return this->c; }
    inline double getVolume() const { return this->a * this->b * this->c; }

    inline void setA(double val) { this->a = val; }
    inline void setB(double val) { this->b = val; }
    inline void setC(double val) { this->c = val; }

    friend bool operator==(Parallelepiped, Parallelepiped);
    friend bool operator!=(Parallelepiped, Parallelepiped);
    friend bool operator>(Parallelepiped, Parallelepiped);
    friend bool operator<(Parallelepiped, Parallelepiped);

    friend ostream& operator<<(ostream& stream, const Parallelepiped& obj);
    friend istream& operator>>(istream& stream, Parallelepiped& obj);
};