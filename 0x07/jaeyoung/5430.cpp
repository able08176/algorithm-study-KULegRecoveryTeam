//
// Created by 박재영 on 2024. 9. 29..
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        deque<int> deque;
        string buffer;
        cin >> buffer;
        stringstream fstringstream(buffer);

        int m;
        cin >> m;

        cin >> buffer;
        buffer = buffer.substr(1, buffer.size() - 2);
        stringstream arrStream(buffer);
        while (getline(arrStream, buffer, ',')) {
            deque.push_back(stoi(buffer));
        }

        char f;
        bool flag = true;
        while (fstringstream >> f) {
            if (f == 'R') {
                if (flag) flag = false;
                else flag = true;
            } else {
                if (deque.empty()) {
                    cout << "error" << "\n";
                    continue;
                }
                if (flag) deque.pop_front();
                else deque.pop_back();
            }
        }
        if (deque.empty())
            continue;
        cout << "[";
        int size = deque.size();
        if (flag) {
            while (--size) {
                cout << deque.front() << ",";
                deque.pop_front();
            }
            cout << deque.front() << "]" << "\n";
        } else {
            while (--size) {
                cout << deque.back() << ",";
                deque.pop_back();
            }
            cout << deque.back() << "]" << "\n";
        }
    }
}