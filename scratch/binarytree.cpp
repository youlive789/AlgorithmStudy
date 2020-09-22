#include <iostream>
#include "datastructure/BinaryTree.h"

int main() {

    BinaryTree* bt = new BinaryTree();

    for (int idx = 0; idx < 10; idx++) {
        bt->insertNode(idx);
    }

    std::cout << "preorder" << std::endl;
    bt->printTree(0); // preorder
    std::cout << std::endl;
    // result : 0 1 3 7 8 4 9 2 5 6

    std::cout << "inorder" << std::endl;
    bt->printTree(1); // inorder
    std::cout << std::endl;
    // result : 7 3 8 1 9 4 0 5 2 6

    std::cout << "postorder" << std::endl;
    bt->printTree(2); // postorder
    std::cout << std::endl;
    // result : 7 8 3 9 4 1 5 6 2 0

    Node* found = bt->findNode(9);
    std::cout << found->value << std::endl;

    return 0;
}