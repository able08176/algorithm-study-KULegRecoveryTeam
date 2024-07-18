// 강의에서 큐 구현해보라고 한거
//#include <bits/stdc++.h>
//using namespace std;
//
//const int MX = 1000005;
//int dat[MX];
//int head = 0, tail = 0;
//
//void push(int x){
//    dat[tail++] = x;
//}
//
//void pop(){
//    head++;
//}
//
//int front(){
//    return dat[head];
//}
//
//int back(){
//    return dat[tail-1];
//}
//
//void test(){
//  push(10); push(20); push(30);
//  cout << front() << '\n'; // 10
//  cout << back() << '\n'; // 30
//  pop(); pop();
//  push(15); push(25);
//  cout << front() << '\n'; // 30
//  cout << back() << '\n'; // 25
//}
//
//int main(void) {
//  test();
//}


// BOJ 10845 큐
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    queue<int> Q;
//    int N;
//    string op1;
//    int op2;
//
//    cin >> N;
//
//    while(N > 0) {
//        cin >> op1;
//
//        if(op1 == "push") {
//            cin >> op2;
//            Q.push(op2);
//        }
//
//        if(op1 == "front") {
//            if(Q.size() != 0)
//                cout << Q.front() << "\n";
//            else
//                cout << "-1\n";
//        }
//
//        if(op1 == "back") {
//            if(Q.size() != 0)
//                cout << Q.back() << "\n";
//            else
//                cout << "-1\n";
//        }
//
//        if(op1 == "size") {
//            cout << Q.size() << "\n";
//        }
//
//        if(op1 == "empty") {
//            if(Q.empty())
//                cout << "1\n";
//            else
//                cout << "0\n";
//        }
//
//        if(op1 == "pop") {
//            if(Q.empty())
//                cout << "-1\n";
//            else {
//                cout << Q.front() << "\n";
//                Q.pop();
//            }
//        }
//
//        N--;
//    }
//
//    return 0;
//}

// BOJ 18258 큐2
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    string op1;
//    int op2;
//    queue<int> Q;
//
//    cin >> N;
//
//    while(N > 0) {
//        cin >> op1;
//
//        if(op1 == "push") {
//            cin >> op2;
//            Q.push(op2);
//        }
//        if(op1 == "pop") {
//            if(Q.empty())
//                cout << "-1\n";
//            else {
//                cout << Q.front() << "\n";
//                Q.pop();
//            }
//        }
//        if(op1 == "size") {
//            cout << Q.size() << "\n";
//        }
//        if(op1 == "empty") {
//            if(Q.empty())
//                cout << "1\n";
//            else
//                cout << "0\n";
//        }
//        if(op1 == "front") {
//            if(Q.empty())
//                cout << "-1\n";
//            else {
//                cout << Q.front() << "\n";
//            }
//        }
//        if(op1 == "back") {
//            if(Q.empty())
//                cout << "-1\n";
//            else {
//                cout << Q.back() << "\n";
//            }
//        }
//
//        N--;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int main(void) {
//
//    int N;
//    queue<int> cards;
//    bool pushFlag = false;
//
//    cin >> N;
//
//    for(int i=1;i<N+1;i++)
//        cards.push(i);
//
//    while(cards.size() > 1) {
//        if(pushFlag) {
//            cards.push(cards.front());
//            cards.pop();
//            pushFlag = false;
//        } else {
//            cards.pop();
//            pushFlag = true;
//        }
//    }
//
//    cout << cards.front() << "\n";
//
//    return 0;
//}

/* 카드2 <풀이노트>

1이 젤 위, N이 젤 아래
카드가 한 장 남을 때까지 다음 반복
- 젤 위 카드 버리기
- 그 다음 젤 위 카드 젤 바닥으로

마지막 한 장 적힌 수 출력

"젤 위"와 "젤 아래"에서 작업이 이루어진다.
생각해 볼 수 있는 자료구조는
1. 큐
2. 덱

큐로 풀 수 있으니 굳이 덱을 쓰진 않는다. 큐에 1부터 N 순(오름차순)으로 넣는다.
while 문으로 다음 작업을 반복한다.

반복 조건 : 큐 사이즈 > 1

if pushFlag == false
- 맨 위 pop
- pushFlag = true

else (pushFlag == true)
- 맨 위 push 하고 pop
- pushFlag = false

*/
