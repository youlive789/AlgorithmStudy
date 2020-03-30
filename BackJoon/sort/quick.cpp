#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void quicksort(vector<int> & arr);
void quick(vector<int> & arr, int start, int end);
int partition(vector<int> & arr, int start, int end);

int main() {

    int cases;
    cin >> cases;
    vector<int> tester;

    for (int i = 0; i < cases; i++) {
        int in;
        scanf("%d", &in);
        tester.push_back(in);
    }

    quicksort(tester);

    for (auto ele : tester) {
        printf("%d\n", ele);
    }

    return 0;
}

void quicksort(vector<int> & arr) {
    quick(arr, 0, arr.size() - 1);
}

void quick(vector<int> & arr, int start, int end) {

    int part = partition(arr, start, end);
    
    if (start < part - 1) {
        quick(arr, start, part - 1);
    }

    if (part < end) {
        quick(arr, part, end);
    }
}

int partition(vector<int> & arr, int start, int end) {
    int pivot = arr[(start + end) / 2];
    while(start <= end) {
        while(arr[start] < pivot) start++;
        while(pivot < arr[end]) end--;
        if (start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    return start;
}