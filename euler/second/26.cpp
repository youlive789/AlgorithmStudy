#include <iostream>
#include <string>

using namespace std;

int circleSize = 0;

bool isCircle(const string& target) {
    if (target == "" || target.size() <= 1) {
        return false;
    }
    else {
        int windowSize = 1;
        while(true) {

            int targetLength = target.size();
            if (targetLength - windowSize < windowSize) break;
            
            for (int pos = 0; pos < target.size() - windowSize; pos++) {

                string testWindow = target.substr(pos, windowSize);
                string remainWindow = target.substr(pos + windowSize, windowSize);

                if (testWindow == remainWindow) {
                    circleSize = windowSize;
                    return true;
                }
            }

            windowSize++;
        }
        return false;
    }
}

int getCircleSize(int N) {

    string target = "";
    int q = 10;

    // 순환일때까지 반복
    while(true) {

        int comp = 1, compTester = N;
        while (compTester) {
            compTester /= 10;
            comp *= 10;
        }

        // 현재 몫(10 / N)을 임시 문자열에 붙인다.
        target.push_back((q / N) + '0');
        // 몫을 10 % N으로 업데이트 한다.
        q = (q % N) * comp;

        // 나누어 떨어지면 리턴
        if (q == 0) return 0;

        // 순환마디를 찾으면 리턴
        if (isCircle(target)) return circleSize;
    }
}

int main() {
    
    int size = 0, answer = 0;
    for (int i = 3; i <= 1000; i++) {
        int nowCircleSize = getCircleSize(i);
        
        if (size < nowCircleSize) {
            size = nowCircleSize;
            answer = i;
        }
    }

    cout << answer << endl;

    return 0;
}