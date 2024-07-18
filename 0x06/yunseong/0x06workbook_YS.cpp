// ���ǿ��� ť �����غ���� �Ѱ�
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


// BOJ 10845 ť
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

// BOJ 18258 ť2
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

/* ī��2 <Ǯ�̳�Ʈ>

1�� �� ��, N�� �� �Ʒ�
ī�尡 �� �� ���� ������ ���� �ݺ�
- �� �� ī�� ������
- �� ���� �� �� ī�� �� �ٴ�����

������ �� �� ���� �� ���

"�� ��"�� "�� �Ʒ�"���� �۾��� �̷������.
������ �� �� �ִ� �ڷᱸ����
1. ť
2. ��

ť�� Ǯ �� ������ ���� ���� ���� �ʴ´�. ť�� 1���� N ��(��������)���� �ִ´�.
while ������ ���� �۾��� �ݺ��Ѵ�.

�ݺ� ���� : ť ������ > 1

if pushFlag == false
- �� �� pop
- pushFlag = true

else (pushFlag == true)
- �� �� push �ϰ� pop
- pushFlag = false

*/
