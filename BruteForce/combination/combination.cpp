#include <iostream>
#include <string>
#include <vector>

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

// n:전체 원소의 수
// picked: 지금까지 고른 원소들의 번호
// toPick: 더 고를 원소의 수
// 일 때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력한다.
void pick(int n, std::vector<int>& picked, int toPick) {
  // 기저 사례: 더 고를 원소가 없을 때 고른 원소들을 출력한다.
  if (toPick == 0) { 
      for (auto number : picked) {
          std::cout << number << " ";
      }
      std::cout << std::endl;
      return; 
  }
  // 고를 수 있는 가장 작은 번호를 계산한다.
  int smallest = picked.empty() ? 0 : picked.back() + 1;
  // 이 단계에서 원소 하나를 고른다.
  for (int next = smallest; next < n; ++next) {
    picked.push_back(next);
    pick(n, picked, toPick - 1);
    picked.pop_back();
  }
}

int main() {

    //getCombinationByRecursion(0, 5, 4);
    std::vector<int> picked;
    pick(3, picked, 2);
    return 0;
}