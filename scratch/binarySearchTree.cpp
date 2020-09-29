#include <iostream>
#include "datastructure/BinarySearchTree.h"

int main() {

    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(4);
    bst->insert(5);
    bst->insert(6);
    bst->insert(3);
    bst->insert(2);
    bst->insert(1);
    bst->insert(1); // 이미 있는 값입니다.

    std::cout << bst->find(3)->value << " 찾았습니다 !" << std::endl;

    bst->printTree();
    bst->remove(3);
    bst->printTree();
    bst->remove(1);
    bst->printTree();
    bst->remove(4);
    bst->printTree();
    bst->remove(2);
    bst->printTree();
    bst->remove(6);
    bst->printTree();

    return 0;
}