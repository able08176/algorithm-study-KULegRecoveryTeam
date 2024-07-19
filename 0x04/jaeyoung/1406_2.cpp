//
// Created by Admin on 2024-07-20.
//

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void insert(int addr, int num) {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr]!=-1)
        pre[nxt[unused]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) {
        pre[nxt[addr]] = pre[addr];
    }
}

void traverse(void) {
    int it = nxt[0];
    while (it != -1) {
        cout << dat[it];
        it = nxt[it];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    string str;
    cin >> str;
    int cursor = 0;
    for (auto c: str) {
        insert(cursor, c);
        cursor = nxt[cursor];
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'L') {
            if (pre[cursor] != -1)
                cursor = pre[cursor];
        } else if (op == 'D') {
            if (nxt[cursor] != -1)
                cursor = nxt[cursor];
        } else if (op == 'B') {
            if (pre[cursor] != -1) {
                erase(cursor);
                cursor = pre[cursor];
            }
        } else {
            char c;
            cin >> c;
            insert(cursor, c);
            cursor = nxt[cursor];
        }
    }
    traverse();
}