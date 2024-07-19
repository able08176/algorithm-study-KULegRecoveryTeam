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

    // BOJ_2577_solution
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

    // BOJ_1475
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int room_num;
    // cin >> room_num;
    // int freq[10] = {};
    // while (room_num) {
    //     freq[room_num % 10]++;
    //     room_num /= 10;
    // }
    // int ans = 0;
    // for (int i = 0; i < 10; ++i) {
    //     if (i == 6 || i == 9)
    //         continue;
    //     ans = max(ans, freq[i]);
    // }
    // ans = max(ans, (freq[6] + freq[9] + 1) / 2);
    // cout << ans;

    // BOJ 3273
    // 문제의 조건을 확장시켜보자.
    // BOJ 3273 문제는 n개의 서로 다른 양의 정수로 이루어진 수열을 받지만,
    // 수열 안의 양의 정수들이 서로 중복될 수 있는 조건 하의 코드를 짜보았다.

    // 배열 인덱스를 다룰 때는 항상 런아웃 에러 OutofBounds 조심!!
    // 변수의 값 범위 항상 잘 고려하기!!
    int n;
    int indexes[100000] = {};
    int x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> indexes[i];
    }
    cin >> x;

    short occur[2000001];
    fill(occur, occur + 2000001, 0);
    int freq = 0;
    for (int i = 0; i < n; ++i) {
        if (x > indexes[i] && occur[x - indexes[i]])
            freq += occur[x - indexes[i]];
        occur[indexes[i]]++;
    }
    cout << freq;
}
