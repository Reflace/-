#include <iostream>
#include "BinTree.hpp"

using namespace std;
// default construct
int Tst3ConstructDef(int argc, char *argv[]) {
    
    BinTree<int> tree;
    BinTree<int>* treeptr = &tree;
    
    if(tree.Search(treeptr,13) == false && tree.getData() == 0)
    {
    	return false;
    }
    else
    {
    	return true;
    }
    
    return 0;
}
