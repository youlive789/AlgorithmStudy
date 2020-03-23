#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/*
하노이 탑 
1. N-1 개의 디스크를 경유지로 옮긴다.
2. 마지막 디스크를 목적지로 옮긴다.
3. 경유지의 디스크를 옮긴다.
*/

vector<pair<int, int> > v;

void hanoi(int n, int from, int by, int to) {
    if (n == 1) v.push_back(make_pair(from, to));
    else {
        hanoi(n-1, from, to, by);
        v.push_back(make_pair(from, to));
        hanoi(n-1, by, from, to);
    }
}
int main() {

    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    printf("%ld\n", v.size());
    for (int i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);

    return 0;
}