#include <iostream>
#include <string>
#include "datastructure/Queue.h"

int main() {
    Queue<std::string>* queue = new Queue<std::string>();
    queue->push("test1");
    queue->push("test2");
    queue->push("test3");
    std::cout << queue->top() << std::endl;

    queue->pop();
    std::cout << queue->top() << std::endl;

    queue->pop();
    std::cout << queue->top() << std::endl;

}