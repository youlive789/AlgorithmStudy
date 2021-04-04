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
        for (int idx = 0; idx < dnaLength; ++idx) {
            if (dnaContainer[idx].find(tmp.at(idx)) != dnaContainer[idx].end()) {
                dnaContainer[idx][tmp.at(idx)]++;
            }
            else {
                dnaContainer[idx][tmp.at(idx)] = 1;
            }            
        }
    }

    // dna 만들기
    std::string answer;
    int hammingDistance = 0;
    for (int i = 0; i < dnaLength; ++i) {
        auto pair 
            = std::max_element(dnaContainer[i].begin(), dnaContainer[i].end(), [] (const std::pair<char, int> & p1, const std::pair<char, int> & p2) {return p1.second < p2.second;});
        answer += pair->first;
        hammingDistance += (dnaCount - pair->second);
    }

    std::cout << answer << std::endl;
    std::cout << hammingDistance << std::endl;

    return 0;
}