//
// Created by 박재영 on 2024. 7. 14..
//
#include <bits/stdc++.h>
using namespace std;


int func1_pjy(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < x) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}

void test1_pjy() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    func1_pjy(arr, x);
}

int main() {
    test1_pjy();
}