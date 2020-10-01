#include <iostream>
#include <string>
#include "datastructure/Stack.h"

int main() {

    Stack<std::string>* stack = new Stack<std::string>();
    stack->pop();
    stack->push("1");
    stack->push("2");
    stack->push("3");
    std::cout << stack->top() << std::endl;

    stack->pop();
    std::cout << stack->top() << std::endl;

    return 0;
}