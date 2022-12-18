#include <iostream>
#include "BinTree.hpp"

using namespace std;

int Tst5IsEmpty(int argc, char *argv[]) {
    
    //BinTree<int> tree;
    BinTree<int>* treeptr;
    if(treeptr->is_empty(treeptr))
    {
	return false;
    }
    else {
    	return true;
    }
    
    
}
