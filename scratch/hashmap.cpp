#include <iostream>
#include "datastructure/HashMap.h"

using namespace std;

int main() {

    HashMap<string, int>* hashmap = new HashMap<string, int>() ;

    hashmap->put("abc", 213);
    hashmap->put("bcd", 1234345);

    cout << hashmap->get("abc") << endl;
    cout << hashmap->get("bcd") << endl;

    hashmap->put("abc", 41235);
    hashmap->put("bcd", 12323455);

    cout << hashmap->get("abc") << endl;
    cout << hashmap->get("bcd") << endl;

    return 0;
}