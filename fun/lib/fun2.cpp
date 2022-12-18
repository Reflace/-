#include "fun.hpp"

double fun1(double x) {
    if(x < (-8.)) return -3.;
    
    if(x >= (-8.) && x < (-3.)) return (3./5.) * x + (9./5.);

    if(x >= (-3.) && x <= 3.) return -sqrt(9 - pow(x, 2));

    if(x > 3. && x < 5.) return x - 2.; //wrong function

    if(x >= 5.) return 3.;
};

bool fun2(double x, double y) {
    bool circle = (pow(x, 2) + pow(y, 2) <= pow(RADIUS + 3, 2)) && (x <= 0) && (y >= 0); //circle is bigger
    bool triangle = (x >= 0 && y <= 0) && (y >= 2. * x - 8) && (y >= (-2.) * x);
    if(circle || triangle) return true;
    return false;
};