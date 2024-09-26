//
// Created by 박재영 on 2024. 8. 12..
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string buffer;
    queue<int> queue;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> buffer;
        if (buffer == "push") {
            int k;
            cin >> k;
            queue.push(k);
        } else if (buffer == "pop") {
            if (queue.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << queue.front() << "\n";
            queue.pop();
        } else if (buffer == "size") {
            cout << queue.size() << "\n";
        } else if (buffer == "empty") {
            if (queue.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        } else if (buffer == "front") {
            if (queue.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << queue.front() << "\n";
        } else {
            if (queue.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << queue.back() << "\n";
        }
    }
}