#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long series[100001];

int main() {
    
    int seriesSize;
    scanf("%d", &seriesSize);

    for (int i = 0; i < seriesSize; ++i) {
        scanf("%llu", &series[i]);
    }

    int querySize;
    scanf("%d", &querySize);
    for (int i = 0; i < querySize; ++i) {
        long long number;
        int query, index, min;
        scanf("%d %d %llu", &query, &index, &number);

        switch (query)
        {
        case 1:
            index--;
            series[index] = number;
            break;
        case 2:
            index--;
            min = *min_element(series + index, series + number);
            printf("%d\n", min);
            break;
        default:
            break;
        }
    }

    return 0;
}