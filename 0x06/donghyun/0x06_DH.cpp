#include <bits/stdc++.h>
using namespace std;

/* 연습문제 : 10258 사실상 10845랑 거의 똑같음
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> Q;
    while (n--) {
        string str;
        cin >> str;
        if (str == "push") {
            int i;
            cin >> i;
            Q.push(i);
        }
        else if (str == "pop") {
            if(Q.empty()) { cout << "-1\n"; }
            else {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (str == "size") cout << Q.size() << "\n";
        else if (str == "empty") cout << Q.empty() << "\n";
        else if (str == "front") {
            if (Q.empty()) cout << "-1\n";
            else cout << Q.front() << "\n";
        }
        else {
            if (Q.empty()) cout << "-1\n";
            else cout << Q.back() << "\n";
        }
    }
}
*/
/* 연습문제 : 2164 */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> Q;
    for (int i = 1; i < n + 1; i++) Q.push(i);
    while (Q.size() != 1) {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout << Q.front();
}

// 큐와 스택의 차이점 : First in Fist Out / First in Last Out
// 큐는 스택과 달리 front를 통해 맨앞의 원소에 접근이 가능함
