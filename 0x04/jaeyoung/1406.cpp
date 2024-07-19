//
// Created by Admin on 2024-07-20.
//

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    list<char> c_list;
    for (auto c: str) {
        c_list.push_back(c);
    }
    auto it = c_list.end();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'L') {
            if (it != c_list.begin())
                it--;
        } else if (op == 'D') {
            if (it != c_list.end())
                it++;
        } else if (op == 'B') {
            if (it != c_list.begin()) {
                it--;
                it = c_list.erase(it);
            }
        } else {
            char c;
            cin >> c;
            c_list.insert(it, c);
        }
    }
    for (auto c: c_list) {
        cout << c;
    }
}
