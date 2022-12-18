#include <iostream>
#include <vector>

#include "ShellSort.hpp"

using namespace std;

int Tst2Lst(int argc, char *argv[]) {
    	//Predicat op1;
	vector<double> vec = { 44.1, -55, 12.8, 42,
		-94.7, 18, 6, 67, -70, 9, 3.4, 97, -34, 20.1, 25, 10.2};
	int *mas = new int[3]{1,4,7};
	int count = 15;
	//ShellSort(vec.begin(), vec.end(), mas, 3, op1);
	for(int i = 1; i <= 15; i++)
	{
		if (abs(vec[i-1]) > abs(vec[i])) continue;
	}
	if(count == 15) return false;
	else return true;
    		
}
