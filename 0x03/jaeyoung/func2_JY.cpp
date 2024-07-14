//
// Created by 박재영 on 2024. 7. 14..
//
#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int n) {
    int freq[101] = {0};
    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (freq[100 - arr[i]])
            return 1;
    }
    return 0;
}

int func2_solution(int arr[], int n) {
    int occur[101] = {};
    for (int i = 0; i < n; ++i) {
        if (occur[100 - arr[i]])
            return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}

int main(void) {
    int arr1[] = {1, 52, 48};
    int arr2[] = {50, 42};
    int arr3[] = {4, 13, 63, 87};

    cout << func2(arr1, 3) << "\n";
    cout << func2(arr2, 2) << "\n";
    cout << func2(arr3, 4) << "\n";
}
