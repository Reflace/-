#include <iostream>
#include "BinTree.hpp"

using namespace std;

int Tst4Del(int argc, char *argv[]) {
    
    BinTree<int> tree(13);
    BinTree<int>* treeptr = &tree;
    
    for(int i = 0; i < 100; i++)
    {	
    	treeptr = tree.Insert(treeptr, i);
    }
    
    treeptr = tree.Delete(treeptr, 56);
    treeptr = tree.Delete(treeptr, 32);
    if(tree.Search(treeptr, 56) == false && tree.Search(treeptr, 32) == false)
    {
    	return false;
    }
    else {
    	return true;
    }
    
}
