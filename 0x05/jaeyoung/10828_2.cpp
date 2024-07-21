//
// Created by Admin on 2024-07-21.
//
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop(void) {
    if (pos > 0) {
        cout << dat[--pos] << "\n";
    }
    else
        cout << "-1" << "\n";
}

void size(void) {
    cout << pos << "\n";
}

void empty(void) {
    if (pos == 0)
        cout << "1" << "\n";
    else
        cout << "0" << "\n";
}

void top(void) {
    if (pos > 0) {
        cout << dat[pos - 1] << "\n";
    }
    else
        cout << "-1" << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string buffer;
        cin >> buffer;
        if (buffer == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if (buffer == "pop")
            pop();
        else if (buffer == "size")
            size();
        else if (buffer == "empty")
            empty();
        else
            top();
    }
}
