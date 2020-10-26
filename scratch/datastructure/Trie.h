#pragma once
#include <iostream>
#include <vector>

#define ALPHABET_SIZE 26

class Node {
public:
    char _value;
    bool isEnd;
    std::vector<Node> container;
    Node(const char& value) : _value(value) {
        for (int idx = 0; idx < ALPHABET_SIZE; idx++) {
            this->container.push_back('a' + idx);
        }
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        this->root = new Node('\0');
    }

    void insert(const std::string& target) {}

    void insert(const char* target) {}

    void search(const std::string& target) {}

    void search(const char* target) {}
};