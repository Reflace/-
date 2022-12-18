#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <cmath>
#include "Parallelepiped.hpp"
#include "Predicate.hpp"
#include "ShellSort.hpp"
#include <iomanip>

using namespace std;

int main()
{
	Predicate op;
	vector<float> vec;
	for (int i = 0; i < 100; ++i)
	{
		vec.push_back((float)(rand() % 1000) / 10.);
	}

	int *mas = new int[3];

	// Схема Р. Седжвика
	for (int i = 0; i < 3; ++i)
	{
		if (i % 2 == 0)
		{
			mas[i] = (9 * pow(2, i)) - (9 * pow(2, i / 2)) + 1;
		}
		else
		{
			mas[i] = (8 * pow(2, i)) - (6 * pow(2, (i + 1) / 2)) + 1;
		}
	}

	cout << "Unsorted vector: \n";
	for (auto ptr = vec.begin(); ptr != vec.end(); ++ptr)
	{
		cout << *ptr << " ";
	}
	cout << "\n";

	ShellSort(vec.begin(), vec.end(), mas, 3, op);

	cout << "Sorted vec: \n";
	for (auto ptr = vec.begin(); ptr != vec.end(); ++ptr)
	{
		cout << *ptr << " ";
	}
	cout << "\n\n";

	list<int> lst;
	int *mas1 = new int[7];
	int m = 1;
	for (int i = 0; i < 7; ++i)
	{
		mas1[i] = pow(2, m++) - 1;
	}
	for (int i = 0; i < 100; ++i)
	{
		lst.push_back(rand() % 100);
	}

	cout << "Unsorted list: \n";
	for (auto ptr = lst.begin(); ptr != lst.end(); ++ptr)
	{
		cout << *ptr << " ";
	}
	cout << "\n";

	ShellSort(lst.begin(), lst.end(), mas1, 7, op);

	cout << "Sorted list: \n";
	for (auto ptr = lst.begin(); ptr != lst.end(); ++ptr)
	{
		cout << *ptr << " ";
	}
	cout << "\n\n";

	Parallelepiped *arr = new Parallelepiped[15];
	// Подследовательность Д. Кнута
	// h(1) = 1, h(j + 1) = 3h(j) + 1 для j = 1,2,...,t–1
	int *mas2 = new int[3]{1, 4, 13};

	string path = "Text.txt";
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cerr << "Not opened: " << path << endl;
		exit(1);
	}
	int k = 0;
	while (!fin.eof())
	{
		fin >> arr[k++];
		if (k == 15) break;
	}
	fin.close();

	ShellSort(arr, arr + 15, mas2, 3, op);

	cout << "Sorted array: \n";
	for (int i = 0; i < k; i++)
	{
		cout << "(" << i + 1 << ")\t" << arr[i] << "\tVolume = " << arr[i].getVolume() << "\n";
	}
}
