#pragma once
#include <iostream>
#include <vector>

long long sum(std::vector<int> &a) {
    long long sumNumber = 0;
    for (const auto& number : a) {
        sumNumber += number;
    }
    return sumNumber;
}

int main() {

    return 0;
}