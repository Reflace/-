#include "Parallelepiped.hpp"

Parallelepiped::Parallelepiped(double a, double b, double c) {
    this->a = max(a, max(b, c)),
    this->b = min(a, min(b, c)),
    this->c = (a + b + c) - (this->a + this->b);
    swap(this->b, this->c);
}

bool operator==(Parallelepiped p1, Parallelepiped p2) {
    return (p1.a == p2.a) && (p1.b == p2.b) && (p1.c == p2.c);
}

bool operator!=(Parallelepiped p1, Parallelepiped p2) {
    return (p1.a != p2.a) || (p1.b != p2.b) || (p1.c != p2.c);
}

bool operator>(Parallelepiped p1, Parallelepiped p2) {
    return p1.getVolume() > p2.getVolume(); 
}

bool operator<(Parallelepiped p1, Parallelepiped p2) {
    return p1.getVolume() < p2.getVolume(); 
}

ostream& operator<<(ostream& stream, const Parallelepiped& obj) {
    stream << "a = " << obj.a << "\tb = " << obj.b << "\tc = " << obj.c;
    return stream;
}

istream& operator>>(istream& stream, Parallelepiped& obj) {
    stream >> obj.a >> obj.b >> obj.c;
    return stream;
}