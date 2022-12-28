#include <iostream>
#include "agriculture.hpp"
#include "myhash.hpp"

using namespace std;

int main()
{
    AgrProduct ap1(1, "Молоко", "Белгород", 50, 86, 10, 3, 20);
    AgrProduct ap2(2, "Кефир", "Белгород", 50, 82, 15, 3, 30);
    AgrProduct ap3(3, "Картофель", "Воронеж", 100, 97, 3, 1, 10);
    AgrProduct ap4(4, "Яйца", "Новгород", 10, 92, 4, 7, 11);
    AgrProduct ap5(5, "Кабачки", "Орёл", 20, 90, 5, 2, 14);
    AgrProduct ap6(6, "Яблоки", "Краснодар", 150, 99, 3, 4, 12);
    AgrProduct ap7(7, "Кукуруза", "Ставрополь", 100, 97, 9, 4, 17);
    AgrProduct ap8(8, "Сыр", "Брянск", 50, 87, 15, 1, 40);

    Myset ob;
    HashTable op;

    op.Insert(ob, ap1);
    op.Insert(ob, ap2);
    op.Insert(ob, ap3);
    op.Insert(ob, ap4);
    op.Insert(ob, ap5);
    op.Insert(ob, ap6);
    op.Insert(ob, ap7);
    op.Insert(ob, ap8);

    cout << (op.Find(ob, ap5));
    cout << endl;

    op.Print(ob);
    cout << endl;

    op.Erase(ob, ap3);
    op.Print(ob);
    
    return 0;
}