#include "datastructure/ArrayList.h"
#include <iostream>

using namespace std;

int main() {

    ArrayList<int>* list = new ArrayList<int>();
    
    for (int i = 0; i < 64; i++)
        list->add(i);

    for (int i = 0; i < list->size(); i++)
        cout << list->get(i) << endl;

    return 0;
}