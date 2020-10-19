#include <iostream>
#include "datastructure/Heap.h"

int main() {

    Heap<int>* heap = new Heap<int>();
    heap->insert(3);
    heap->insert(1);
    heap->insert(5);
    heap->insert(2);
    heap->insert(8);

    std::cout << heap->top() << std::endl; // 8

    heap->pop();
    std::cout << heap->top() << std::endl; // 5

    return 0;
}