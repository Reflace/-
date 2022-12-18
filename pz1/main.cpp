#include <iostream>
#include <bitset>
#include "Set.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Set A(10, 20);
	cout << "Множество A: " << A;

	A.add(12);
	A.add(15);
	A.add(18);
	A.add(10);
	cout << "Множество A: " << A;
	//A.poisk(12);
	//A.poisk(14);
	A.del(12);
	cout << "Множество A после удаления элемента:" << A;

	Set B(10, 20);
	B.add(15);
	B.add(13);
	B.add(16);
	cout << "Множество B: " << B;
	//B.poisk(15);
	//B.poisk(11);
	cout << endl;

	Set C = A + B;
	cout << "Множество C:результат А + В:"<< C;

	Set D(A);
	D.add(14);
	cout << "Множество D: " << D;

	Set E = D * B;
	cout << "Множество E:результат D*В: " << E;

	Set Q(~E);
	cout << "Множество Q:дополнение E: " << Q;

	Set Y(Q - A);
	cout << "Множество Y:результат Q-A: " << Y;

	return 0;

}