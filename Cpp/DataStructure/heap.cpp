#include <iostream>

using namespace std;

class Node {
public:
    int element;
};

class MaxHeap {
public:
    Node heap[20];
    int heapSize;
};

class MinHeap {
public:
    Node heap[20];
    int heapSize;
};

int main() {

    MaxHeap* maxHeap = new MaxHeap();

    return 0;
}