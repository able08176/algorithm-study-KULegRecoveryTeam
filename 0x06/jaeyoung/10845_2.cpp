//
// Created by 박재영 on 2024. 8. 12..
//

#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
    dat[tail++] = x;
}

int size() {
    return tail - head;
}

int pop() {
    if (size() > 0) {
        return dat[head++];
    } else {
        return -1;
    }
}

int empty() {
    if (size() == 0)
        return 1;
    else
        return 0;
}

int front() {
    if (size() > 0)
        return dat[head];
    else
        return -1;
}

int back() {
    if (size() > 0)
        return dat[tail - 1];
    else
        return -1;
}

int main(void) {
    int n;
    cin >> n;
    string buffer;
    int m;
    for (int i = 0; i < n; ++i) {
        cin >> buffer;
        if (buffer == "push") {
            cin >> m;
            push(m);
        } else if (buffer == "size") {
            cout << size() << "\n";
        } else if (buffer == "pop") {
            cout << pop() << "\n";
        } else if (buffer == "empty") {
            cout << empty() << "\n";
        } else if (buffer == "front") {
            cout << front() << "\n";
        } else {
            cout << back() << "\n";
        }
    }
}