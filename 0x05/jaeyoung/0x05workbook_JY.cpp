//
// Created by Admin on 2024-07-22.
//
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // BOJ 10773
    // int k;
    // cin >> k;
    // stack<int> stack;
    // for (int i = 0; i < k; ++i) {
    //     int n;
    //     cin >> n;
    //     if (n == 0) {
    //         stack.pop();
    //     }
    //     else
    //         stack.push(n);
    // }
    // int sum = 0;
    // while (!stack.empty()) {
    //     sum += stack.top();
    //     stack.pop();
    // }
    // cout << sum;

    // BOJ 1874 스택 수열

    // 첫번째 풀이는 직접 스택 구현하여 해결!
    // 하지만, stl을 사용하는 것이 좀 더 적절해보임.
    // const int MX = 100001;
    // int dat[MX];
    // int pos = 1;
    // int nxt = 1;
    // dat[0] = 0;
    //
    // int n;
    // cin >> n;
    // string buffer = "";
    // for (int i = 0; i < n; ++i) {
    //     int k;
    //     cin >> k;
    //     if (k > dat[pos - 1]) {
    //         while (k != dat[pos - 1]) {
    //             dat[pos++] = nxt++;
    //             buffer += "+\n";
    //         }
    //         pos--;
    //         buffer += "-\n";
    //     }
    //     else if (k == dat[pos - 1]) {
    //         pos--;
    //         buffer += "-\n";
    //     }
    //     else {
    //         cout << "NO";
    //         return 0;
    //     }
    // }
    // cout << buffer;

    // 두번째 풀이는 stl 이용!
    // int n;
    // cin >> n;
    // stack<int> stack;
    // stack.push(0);
    // string buffer = "";
    // int nxt = 1;
    // for (int i = 0; i < n; ++i) {
    //     int k;
    //     cin >> k;
    //     if (k > stack.top()) {
    //         while (k != stack.top()) {
    //             stack.push(nxt++);
    //             buffer += "+\n";
    //         }
    //         stack.pop();
    //         buffer += "-\n";
    //     }
    //     else if (k == stack.top()) {
    //         stack.pop();
    //         buffer += "-\n";
    //     }
    //     else {
    //         cout << "No";
    //         return 0;
    //     }
    // }
    // cout << buffer;

    // BOJ 2493 탑

    // 첫번째 풀이는 시간초과 발생한 잘못된 풀이
    // 시간복잡도는 O(n^2)이므로, 50만^2 = 250000000000 = 2500억
    // 1초에 약 1억번의 연산을 수행하므로, 약 2500초가 걸린다.
    // 해당 문제의 시간제한은 1.5초이므로 시간초과 발생!
    // int n;
    // cin >> n;
    // int arr[500000];
    // for (int i = 0; i < n; ++i) {
    //     cin >> arr[i];
    // }
    // cout << "0 ";
    // for (int i = 1; i < n; ++i) {
    //     for (int j = i - 1; j >= 0; --j) {
    //         if (arr[i] < arr[j]) {
    //             cout << j + 1 << " ";
    //             break;
    //         }
    //         if (j == 0)
    //             cout << "0 ";
    //     }
    // }

    // 두번째 풀이
    // 스택 자료구조를 최대한 이용해보자.
}
