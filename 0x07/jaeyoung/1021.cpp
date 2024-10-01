//
// Created by 박재영 on 2024. 9. 28..
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> deque;
    for (int i = 1; i < n + 1; ++i) {
        deque.push_back(i);
    }

    int k;
    int ldiff, rdiff;
    int cnt = 0;
    while (m--) {
        cin >> k;
        ldiff = find(deque.begin(), deque.end(), k) - deque.begin();
        rdiff = deque.end() - find(deque.begin(), deque.end(), k);

        if (ldiff == 0) {
            deque.pop_front();
        } else if (ldiff <= rdiff) {
            while (ldiff--) {
                deque.push_back(deque.front());
                deque.pop_front();
                cnt++;
            }
            deque.pop_front();
        } else {
            while (rdiff--) {
                deque.push_front(deque.back());
                deque.pop_back();
                cnt++;
            }
            deque.pop_front();
        }
    }
    cout << cnt;
    return 0;
}