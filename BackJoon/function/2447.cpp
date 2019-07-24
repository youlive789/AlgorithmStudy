#include <iostream>

using namespace std;

// 모양틀 초기화
bool shape[2187][2187] = {false};

// 모양틀 범위 체크
bool checkHeight(const int& height, const int& compare) {
    if (height <= compare) {
        return false;
    }
    else {
        return true;
    }
}

// 모양 형성
void makeShape(const int& height, int x, int y) {

    // x와 y 좌표가 모양틀을 벗어난다면 종료
    if (!checkHeight(height, x) && !checkHeight(height, y)) return;
    if (!checkHeight(height, x)) { 
        x = 0;
        y += 3;
    }

    shape[y][x] = true;
    shape[y][x+1] = true;
    shape[y][x+2] = true;
    shape[y+1][x] = true;
    shape[y+1][x+2] = true;
    shape[y+2][x] = true;
    shape[y+2][x+1] = true;
    shape[y+2][x+2] = true;

    makeShape(height, x + 3, y);
}

int main() {

    // 높이 입력
    int height = 0;
    cin >> height;

    makeShape(height, 0, 0);
    
    for (int yIndex = 0; yIndex < height; ++yIndex) {
        for (int xIndex = 0; xIndex < height; ++xIndex) {
            // 별 프린트
            if (shape[yIndex][xIndex]) {
                cout << "*";
            } 
            // 공백 프린트
            else {
                cout << "■";
            }
        }
        cout << endl;
    }

    return 0;
}