#include "frustum.hpp"

Frustum::Frustum() {
    this->h = 0;
    this->r1 = 0;
    this->r2 = 0;
}

Frustum::Frustum(double h, double r1, double r2) {
    this->h = h;
    this->r1 = r1;
    this->r2 = r2;
}

double Frustum::Volume() {
    return 1./3. * M_PI * (pow(r1, 2) + r1 * r2 + pow(r2, 2)) * h;
}

bool operator == (Frustum f1, Frustum f2) {
    return (f1.h == f2.h) && (f1.r1 == f2.r1) && (f1.r2 == f2.r2);
}

bool operator != (Frustum f1, Frustum f2) {
    return (f1.h != f2.h) || (f1.r1 != f2.r1) || (f1.r2 != f2.r2);
}

bool operator > (Frustum f1, Frustum f2) {
    return f1.Volume() > f2.Volume();
}

bool operator < (Frustum f1, Frustum f2) {
    return f1.Volume() < f2.Volume();
}

ostream& operator<<(ostream& stream, const Frustum& obj) {
    stream << "h = " << obj.h << " r1 = " << obj.r1 << " r2 = " << obj.r2 << endl;
    return stream;
}

istream& operator>>(istream& stream, Frustum& obj) {
    stream >> obj.h >> obj.r1 >> obj.r2;
    return stream;
}