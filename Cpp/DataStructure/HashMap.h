#pragma once
#include <string>
#include "LinkedList.h"

class HashMap {
private:
    int _getValue(const std::string& key) {

    }
public:
    int operator [] (const std::string& key) {
        return _getValue(key);
    }


};