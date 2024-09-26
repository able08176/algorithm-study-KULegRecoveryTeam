//
// Created by 박재영 on 2024. 9. 26..
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        exit(0);
    }

    queue<int> queue;
    for (int i = 1; i <= n; ++i) {
        queue.push(i);
    }

    bool flag = true;
    while (flag) {
        queue.pop();
        queue.push(queue.front());
        queue.pop();
        if (queue.size() == 1)
            flag = false;
    }
    cout << queue.front();
}