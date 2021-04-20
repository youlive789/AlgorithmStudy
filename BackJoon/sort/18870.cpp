#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    /**
     * 아이디어
     * 1. 입력받은 좌표값을 키로, 인덱스를 값으로 갖는 맵 생성
     * 2. 정렬수행
     * 3. 값을 순회하면서 출력할 배열 완성
     * 4. 정답출력
     */

    int count;
    cin >> count;

    vector<int> cords;
    cords.reserve(count);
    for (int i = 0; i < count; ++i) {
        cin >> cords[i];
    }

    sort(cords.begin(), cords.end());
    

    return 0;
}