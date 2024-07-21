//
// Created by Admin on 2024-07-21.
//
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> stack;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string buffer;
        cin >> buffer;
        if (buffer == "push") {
            int x;
            cin >> x;
            stack.push(x);
        }
        else if (buffer == "pop") {
            if (!stack.empty()) {
                cout << stack.top() << "\n";
                stack.pop();
            }
            else
                cout << "-1" << "\n";
        }
        else if (buffer == "size") {
            if (!stack.empty())
                cout << stack.size() << "\n";
            else
                cout << "0" << "\n";
        }
        else if (buffer == "empty") {
            if (stack.empty())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        }
        else {
            if (!stack.empty())
                cout << stack.top() << "\n";
            else
                cout << "-1" << "\n";
        }
    }
}
