#include <iostream>
#include "datastructure/BinarySearchTree.h"

int main() {

    BinarySearchTree* bst = new BinarySearchTree();
    // [1, 2, 3, 4, 5]
    bst->insert(3);
    bst->insert(1);
    bst->insert(2);
    bst->insert(4);
    bst->insert(5);
    
    bst->printTree();
    std::cout << bst->find(3) << std::endl;

    bst->remove(1);

    return 0;
}