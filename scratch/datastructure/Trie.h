#pragma once
#include <iostream>
#include <vector>

#define ALPHABET_SIZE 26

class Node {
public:
    bool isEnd;
    Node* container[ALPHABET_SIZE];
    Node() {
        for (int idx = 0; idx < ALPHABET_SIZE; idx++) {
            this->container[idx] = nullptr;
        }
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        this->root = new Node();
    }

    void insert(const std::string& target) {
        Node* cursor = this->root;
        for (char element : target) {
            if (!cursor->container[element - 'a']) {
                cursor->container[element - 'a'] = new Node();
            }
            cursor = cursor->container[element - 'a'];
        }
        cursor->isEnd = true;
    }

    bool search(const std::string& target) {
        bool result = true;
        Node* cursor = this->root;
        for (char element : target) {
            if (!cursor->container[element - 'a']) {
                result = false;
                break;
            }
            cursor = cursor->container[element - 'a'];
        }
        if (!cursor->isEnd) {
            result = false;
        }

        return result;
    }

};