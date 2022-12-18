#include <iostream>
#include "frustum.hpp"
#include "BinTree.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    Frustum A(3, 2, 1), B(1, 2, 1), C(1, 1, 2), D(3, 4, 5), E(2, 2, 2);
    BinTree<Frustum>* tree; 
    tree = tree->Insert(tree, A);
    tree = tree->Insert(tree, B);
    tree = tree->Insert(tree, C);
    tree = tree->Insert(tree, D);
    tree = tree->Insert(tree, E);

    tree->print(tree, 0);
    return 0;
}