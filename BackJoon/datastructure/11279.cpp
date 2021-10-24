#include <cstdio>
#include <queue>

using namespace std;

int main() {

    priority_queue<unsigned long long> q;

    int count;
    scanf("%d", &count);

    while (count--) {
        unsigned long long number;
        scanf("%llu", &number);

        if (number == 0) {
            if (q.empty()) {
                printf("%llu\n", 0);
            }
            else {
                printf("%llu\n", q.top());
                q.pop();
            }
        }
        else {
            q.push(number);
        }
    }

    return 0;
}