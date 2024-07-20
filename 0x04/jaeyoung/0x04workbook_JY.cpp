//
// Created by Admin on 2024-07-20.
//

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // BOJ 5397 키로거

    // while(cin >> n)의 문제 발견
    // cin의 특징을 명확히 알도록 하자!
    // 키로거 문제의 경우 각각의 입력의 한 줄 한 줄에 공백이 없다.
    // 따라서, getline을 쓰는 것보다는 직접 cin >> str으로 받는 것이 깔끔한 풀이!
    // getline을 쓰면 공백까지 받으므로, 버퍼나 스트림에 남아있던 개행문자등이 문제를 일으킬 수 있음!
    // 스트림과 버퍼에 대한 확실한 공부가 필요할 듯..

    // int n;
    // cin >> n;
    //
    // for (int i = 0; i < n; ++i) {
    //     list<char> keylog;
    //     auto it = keylog.end();
    //     string buffer;
    //     cin >> buffer;
    //     for (auto c: buffer) {
    //         if (c == '<') {
    //             if (it != keylog.begin())
    //                 it--;
    //         }
    //         else if (c == '>') {
    //             if (it != keylog.end())
    //                 it++;
    //         }
    //         else if (c == '-') {
    //             if (it != keylog.begin()) {
    //                 it--;
    //                 it = keylog.erase(it);
    //             }
    //         }
    //         else {
    //             keylog.insert(it, c);
    //         }
    //     }
    //     for (auto c: keylog) {
    //         cout << c;
    //     }
    //     cout << "\n";
    // }

    // BOJ 1158 요세푸스 문제

    // 요세푸스 문제 중요!
    // 윤성이 코드 리뷰에서 작성한 메모 참조하자!
    // queue, vector로 푸는 풀이도 생각해보기!
    // 원형 리스트 풀이도 생각해보기!

    // int n, k;
    // cin >> n >> k;
    // list<int> list;
    // for (int i = 1; i <= n; ++i) {
    //     list.push_back(i);
    // }
    // auto it = list.begin();
    // cout << "<";
    // while (!list.empty()) {
    //     for (int i = 0; i < k - 1; ++i) {
    //         if (it == list.end())
    //             it = list.begin();
    //         it++;
    //         if (it == list.end())
    //             it = list.begin();
    //     }
    //     cout << *it;
    //     it = list.erase(it);
    //     if (!list.empty())
    //         cout << ", ";
    //
    // }
    // cout << ">";
}
