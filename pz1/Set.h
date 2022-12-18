#pragma once

#include <iostream>
#include <bitset>

using namespace std;

class Set
{
public:
	char* ptr;
	int n, l, r;
	Set(int a, int b);
	~Set();
	Set(const Set& obj);

	bool poisk(int);
	void add(int);
	void del(int);

	friend ostream& operator <<(ostream& potok, Set& C);
	friend Set operator+(Set A, Set B);
	friend Set operator*(Set A, Set B);
	friend Set operator-(Set A, Set B);
	friend Set operator~(Set A);
};

