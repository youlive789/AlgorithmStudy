#include <iostream>
#include <string>

#include "datastructure/Trie.h"

int main() {

    Trie* trie = new Trie();
    trie->insert("abd");
    trie->insert("bcd");
    trie->insert("hello");

    std::cout << std::boolalpha;
    std::cout << trie->search("abd") << std::endl; // true
    std::cout << trie->search("abc") << std::endl; // false
    std::cout << trie->search("hello") << std::endl; // true

    return 0;
}