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

//    int n;
//    int indexes[100000] = {};
//    int x;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cin >> indexes[i];
//    }
//    cin >> x;
//
//    short occur[2000001];
//    fill(occur, occur + 2000001, 0);
//    int freq = 0;
//    for (int i = 0; i < n; ++i) {
//        if (x > indexes[i] && occur[x - indexes[i]])
//            freq += occur[x - indexes[i]];
//        occur[indexes[i]]++;
//    }
//    cout << freq;

    // BOJ 3273 별해
    // 두 수의 합을 다루는 문제에서 내가 처음에 틀렸던 코드,
    // 먼저 occur 올리고, 그 다음에 체크하는 알고리즘의 문제는
    // 중간값에서 문제가 발생했음.
    // 밑의 별해는 먼저 occur을 올리고, 그 다음에 체크시 체크하는 횟수를
    // 반만 시행하므로 중간값에서 문제 방지.

    // 각 자연수의 존재 여부를 저장하는 배열, 배열의 크기를 200만으로 두어
    // 25번째 줄에서 x-i의 범위를 별도로 체크하지 않아도 되게끔 했다.
    int a[2000001] = {};

    int n, t, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a[t]++;
    }

    cin >> x;
    for (int i = 1; i < (x + 1) / 2; ++i) {
        // 합이 x가 되는 서로 다른 자연수 (i,x-i)가 존재할 경우
        if (a[i] == 1 && a[x - i] == 1) ans++;
    }
    cout << ans;
    /*
    x가 짝수일 때에는 (x/2 - 1)까지, 홀수일 때에는 (x-1)/2까지 탐색할 수 있도록 하기 위해서
    i < (x+1)/2로 뒀음. 직접 x가 10일 때 / 11일 때를 생각해보면 이해 가능
    이 코드는 O(n+x)에 동작, x가 최대 200만이므로 통과에는 문제가 없으나 O(n)에 비해서는 느림.
    */
}
