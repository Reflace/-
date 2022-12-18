#include <iostream>
#include "fun.hpp"

int main() {
    double x, y;

    cin >> x;
    cout << boolalpha << "fun1: " << fun1(x) << endl;

    cin >> x >> y;
    cout << "fun2: " << fun2(x, y) << endl;
    return 0;
}