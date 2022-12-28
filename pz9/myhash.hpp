#include <iostream>
#include <fstream>
#include <unordered_set>
#include "agriculture.hpp"

using namespace std;

class MyHash
{
public:
    size_t operator()(const AgrProduct &obj) const
    {
        return obj.get_key() % 7;
    }
};

typedef unordered_set<AgrProduct, MyHash> Myset;

class HashTable
{
public:
    void Insert(Myset &ob, AgrProduct &x)
    {
        ob.insert(x);
    }
    void Erase(Myset &ob, AgrProduct &y)
    {
        ob.erase(y);
    }
    AgrProduct Find(Myset &ob, AgrProduct &z)
    {
        return *(ob.find(z));
    }
    void Print(Myset &ob)
    {
        for (int i = 0; i < 7; ++i)
        {
            for (auto ptr = ob.begin(i); ptr != ob.end(i); ptr++)
                cout << *ptr;
            cout << endl;
        }
    }
};