//
// Created by 박재영 on 2024. 9. 28..
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string buffer;
    deque<int> deque;
    for (int i = 0; i < n; ++i) {
        cin >> buffer;
        if (buffer == "push_front") {
            int k;
            cin >> k;
            deque.push_front(k);
        } else if (buffer == "push_back") {
            int k;
            cin >> k;
            deque.push_back(k);
        } else if (buffer == "pop_front") {
            if (deque.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << deque.front() << "\n";
            deque.pop_front();
        } else if (buffer == "pop_back") {
            if (deque.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << deque.back() << "\n";
            deque.pop_back();
        } else if (buffer == "size") {
            cout << deque.size() << "\n";
        } else if (buffer == "empty") {
            if (deque.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        } else if (buffer == "front") {
            if (deque.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << deque.front()<<"\n";
        } else {
            if (deque.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << deque.back() << "\n";
        }
    }
}