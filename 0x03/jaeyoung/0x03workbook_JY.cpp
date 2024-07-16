//
// Created by Admin on 2024-07-14.
//
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    // BOJ_2577
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int freq[10] = {};
    // int a, b, c;
    // cin >> a >> b >> c;
    // int m = a * b * c;
    // string m_string = to_string(m);
    // for (auto c: m_string) {
    //     freq[c - '0']++;
    // }
    // for (auto n: freq) {
    //     cout << n << "\n";
    // }

    //BOJ_2577_solution
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int a, b, c;
    // int freq[10] = {};
    // cin >> a >> b >> c;
    // int t = a * b * c;
    // while (t > 0) {
    //     freq[t % 10]++;
    //     t /= 10;
    // }
    // for (auto n: freq) {
    //     cout << n << "\n";
    // }

    //BOJ_1475
    ios::sync_with_stdio(0);
    cin.tie(0);
    int room_num;
    cin >> room_num;
    int freq[10] = {};
    while (room_num) {
        freq[room_num % 10]++;
        room_num /= 10;
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        if (i == 6 || i == 9)
            continue;
        ans = max(ans, freq[i]);
    }
    ans = max(ans, (freq[6] + freq[9] + 1) / 2);
    cout << ans;
}
