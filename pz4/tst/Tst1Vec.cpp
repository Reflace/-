#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Predicate.hpp"
#include "ShellSort.hpp"

using namespace std;

int Tst1Vec(int argc, char *argv[])
{
	Predicate op;
	vector<double> vec = {44.1, -55, 12.8, 42, -94.7, 18, 6, 67, -70, 9, 3.4, 97, -34, 20.1, 25, 10.2, 923, 293.2, 90, 87.5};
	int *mas = new int[3]{1, 4, 7};
	ShellSort(vec.begin(), vec.end(), mas, 3, op);
	if(is_sorted(vec.begin(), vec.end())) return false;
	else return true;
}
