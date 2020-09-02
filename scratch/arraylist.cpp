#include "datastructure/ArrayList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

    ArrayList<string>* list = new ArrayList<string>();
    
    for (int i = 0; i < 5; i++)
        list->add("test");

    list->pop_back();

    for (int i = 0; i < list->size(); i++)
        cout << list->get(i) << endl;

    return 0;
}