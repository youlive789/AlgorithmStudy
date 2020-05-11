#include <iostream>
#include "LinkedList.h"
#include "HashMap.h"

int main() {
    
    HashMap* hashmap = new HashMap();

    hashmap->set("와우!", 666);
    std::cout << hashmap->get("와우!") << std::endl;

    hashmap->set("와우!", 7894561);
    std::cout << hashmap->get("와우!") << std::endl;

    hashmap->set("와", 7891);
    std::cout << hashmap->get("와") << std::endl;
    return 0;
}