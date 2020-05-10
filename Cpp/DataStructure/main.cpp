#include <iostream>
#include "LinkedList.h"

int main() {
    
    LinkdedList* list = new LinkdedList();
    for (int i = 0; i < 10; i++) {
        list->insertNode(new Node(i));
    }

    list->deleteNode(5);
    list->printList();

    std::cout << "get : " << list->getNode(5) << std::endl;

    delete[] list;

    return 0;
}