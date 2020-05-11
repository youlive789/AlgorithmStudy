#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

class HashMap {
private:
    LinkdedList* stored[3];

    int _getValue(const std::string& key) {
        std::pair<bool, int> chk = this->_find(key);
        if (chk.first) {    
            return chk.second;
        }
        else {
            throw "Not Found.";
        }
    }

    std::pair<bool, int> _find(const std::string& key) {
        int hashCode = this->_hash(key);
        Node* cursor = this->stored[hashCode]->head;
        while (cursor != nullptr) {
            if (cursor->key == key) {
                return std::make_pair(true, cursor->data);
            }
        }
        return std::make_pair(false, -1);
    }

    void _setValue(const std::string& key, const int& value) {
        
        int hashCode = this->_hash(key);
        std::pair<bool, int> chk = this->_find(key);

        // 키가 없다면 삽입
        if (!chk.first) {
            Node* node = new Node(value);
            node->key = key;
            this->stored[hashCode]->insertNode(node);
        }
        // 덮어쓰기
        else {
            this->_overwrite(key, hashCode, value);
        }
    }

    void _overwrite(const std::string& key, const int& hashCode, const int& value) {
        Node* cursor = this->stored[hashCode]->head;
        while (cursor != nullptr) {
            if (cursor->key == key) {
                cursor->data = value;
            }
            cursor = cursor->next;
        }
    }

    int _hash(const std::string& key) {
        int hashCode = 0;
        for (char k : key) {
            hashCode += (int)k;
        }
        return hashCode % 3;
    }

public:
    HashMap() {
        this->stored[0] = new LinkdedList();
        this->stored[1] = new LinkdedList();
        this->stored[2] = new LinkdedList();
    }

    int get(const std::string& key) {
        return this->_getValue(key);
    }

    void set(const std::string& key, const int& value) {
        this->_setValue(key, value);
    }

    void erase(const std::string& key) {

    }
};