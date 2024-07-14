//
// Created by 박재영 on 2024. 7. 14..
//

// 개발 style~
//#include <iostream>
//
//int main(void) {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    int n, x;
//    std::cin >> n >> x;
//
//    int* arr = new int[n];
//    for (int i = 0; i < n; ++i) {
//        std::cin >> arr[i];
//    }
//    for (int i = 0; i < n; ++i) {
//        if (arr[i] < x) {
//            std::cout << arr[i] << " ";
//        }
//    }
//    delete[] arr;
//    arr = nullptr;
//}

// 코딩테스트 style~
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, x, a[10005];
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> n >> x;
//    for (int i = 0; i < n; ++i) cin >> a[i];
//    for (int i = 0; i < n; ++i)
//        if (a[i] < x) cout << a[i] << " ";
//}

// 코딩테스트 style ver2~
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, t;
    cin >> n >> x;
    while (n--) {
        cin >> t;
        if (t < x) cout << t << " ";
    }
}