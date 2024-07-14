//
// Created by 박재영 on 2024. 7. 14..
//

#include <bits/stdc++.h>

using namespace std;

//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    string s;
//    cin >> s;
//    for (char c = 'a'; c <= 'z'; c++) {
//        int cnt = 0;
//        for (auto k: s) {
//            if (k == c)
//                cnt++;
//        }
//        cout << cnt << " ";
//    }
//}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int freq[26] = {0};
    string s;
    cin >> s;
    for (auto c : s) {
        freq[c - 'a']++;
    }
    for (auto n : freq) {
        cout << n << " ";
    }
}