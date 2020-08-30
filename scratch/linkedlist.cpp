#include <string>
#include <iostream>
#include "datastructure/LinkedList.h"

using namespace std;

int main() {

    LinkedList<string>* list = new LinkedList<string>();
    list->add("abc");
    list->add("bca");
    list->add("cba");

    for (int i = 0; i < list->length(); i++) {
        cout << list->get(i) << endl;
    }

    cout << endl;
    list->remove(1);

    for (int i = 0; i < list->length(); i++) {
        cout << list->get(i) << endl;
    }

    return 0;
}