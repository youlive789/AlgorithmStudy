#include <iostream>
#include <algorithm>
using namespace std;
 
int sensor[10000];
int dist[999];
int result;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    int N, K;
    cin >> N >> K;
 
    for (int i = 0; i < N; i++)
        cin >> sensor[i];
 
    sort(sensor, sensor + N);
 
    // 인접한 센서 사이의 거리
    for (int i = 0; i < N - 1; i++)
        dist[i] = sensor[i + 1] - sensor[i];
 
    // 거리 내림차순 정렬
    sort(dist, dist + (N - 1), greater<int>());
 
    // 거리가 먼 순서대로 삭제
    for (int i = 0; i < K - 1; i++) dist[i] = 0;
 
    for (int i = 0; i < N - 1; i++) result += dist[i];
 
    cout << result;
 
    return 0;
}
