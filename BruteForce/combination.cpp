#include <iostream>
#include <string>

// 주어진 수열에서 조합을 가져온다.
// 문제가 있는 접근법이다. 수열의 크기나,
// 조합의 크기를 무시하고 지멋대로 조합을 가져온다.
void getCombinationByRecursion(
    const int& startIndex,       // 수열의 시작 인덱스
    const int& sequenceEndIndex, // 수열의 끝 인덱스
    const int& combinationSize   // 조합의 수 - 몇개를 뽑을 것인가?
) {

    if (combinationSize > sequenceEndIndex) return;
    if (startIndex >= sequenceEndIndex - 1) return;
    std::string combinatinonString = "";

    // 주어진 수열의 크기만큼 반복한다.
    for (int sequenceIndex = startIndex + 1; sequenceIndex < sequenceEndIndex; ++sequenceIndex) {
        combinatinonString.append(" ( ");
        combinatinonString.append(std::to_string(startIndex));
        combinatinonString.append(",");
        // 뽑을 조합만큼 순회하면서 숫자를 선택한다.
        for (int combinationIndex = 0; combinationIndex < combinationSize - 1; ++combinationIndex) {
            combinatinonString.append(std::to_string(sequenceIndex + combinationIndex));
            // 마지막 숫자 전까지면 쉼표를 붙인다.
            if (combinationIndex < combinationSize - 2) {
                combinatinonString.append(",");
            }
        }
        combinatinonString.append(" ) ");          
    }

    std::cout << combinatinonString << std::endl;
    getCombinationByRecursion(startIndex + 1, sequenceEndIndex, combinationSize); 
}

int main() {

    getCombinationByRecursion(0, 5, 4);
    return 0;
}