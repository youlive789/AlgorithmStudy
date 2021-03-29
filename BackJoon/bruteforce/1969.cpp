#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {

    int dnaCount, dnaLength;
    std::cin >> dnaCount >> dnaLength;

    // 입력
    std::map<int, std::map<char, int>> dnaContainer;
    for (int i = 0; i < dnaCount; ++i) {
        std::string tmp;
        std::cin >> tmp;
        for (auto c : tmp) {
            if (dnaContainer[i].find(c) != dnaContainer[i].end()) {
                dnaContainer[i][c]++;
            }
            else {
                dnaContainer[i][c] = 1;
            }            
        }
    }

    // dna 만들기
    std::string answer;
    for (int i = 0; i < dnaCount; ++i) {
        auto pair 
            = std::max_element(dnaContainer[i].begin(), dnaContainer[i].end(), [] (const std::pair<char, int> & p1, const std::pair<char, int> & p2) {return p1.second > p2.second;});
        std::cout << pair->first << std::endl;
        answer += pair->first;
    }

    std::cout << answer << std::endl;

    return 0;
}