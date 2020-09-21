#include <iostream>
#include "datastructure/BinaryTree.h"

int main() {

    BinaryTree* bt = new BinaryTree();

    for (int idx = 0; idx < 5; idx++) {
        bt->insertNode(idx);
    }

    bt->printTree();

    return 0;
}