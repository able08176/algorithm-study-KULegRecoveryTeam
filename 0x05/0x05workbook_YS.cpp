//강의에서 배열 스택 구현하라고 한거
//#include <bits/stdc++.h>
//using namespace std;
//
//const int MX = 1000005;
//int dat[MX];
//int pos = 0;
//
//void push(int x){
//    dat[pos++] = x;
//}
//
//void pop(){
//    pos--;
//}
//
//int top(){
//    return dat[pos-1];
//}
//
//void test(){
//  push(5); push(4); push(3);
//  cout << top() << '\n'; // 3
//  pop(); pop();
//  cout << top() << '\n'; // 5
//  push(10); push(12);
//  cout << top() << '\n'; // 12
//  pop();
//  cout << top() << '\n'; // 10
//}
//
//int main(void) {
//	test();
//}


//BOJ 10828 스택
//#include <iostream>
//#include <stack>
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
//    stack<int> S;
//    cin >> N;
//
//    for(int t = 0;t < N;t++) {
//        cin >> op1;
//
//        if(op1 == "push") {
//            cin >> op2;
//            S.push(op2);
//        }
//        if(op1 == "top") {
//            if(S.size() == 0)
//                cout << "-1\n";
//            else
//                cout << S.top() << "\n";
//        }
//        if(op1 == "size") {
//            cout << S.size() << "\n";
//        }
//        if(op1 == "empty") {
//            if(S.empty())
//                cout << "1\n";
//            else
//                cout << "0\n";
//        }
//        if(op1 == "pop") {
//            if(S.empty())
//                cout << "-1\n";
//            else {
//                op2 = S.top();
//                S.pop();
//                cout << op2 << "\n";
//            }
//        }
//    }
//
//    return 0;
//}

//BOJ 54767 제로
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int K;
//    int input;
//    int sum = 0;
//    int op1;
//    stack<int> S;
//
//    cin >> K;
//
//    while(K > 0) {
//        cin >> op1;
//
//        if(op1 == 0)
//        {
//            if(S.size() > 0)
//                S.pop();
//        }
//        else
//            S.push(op1);
//
//        K--;
//    }
//
//    while(S.size() > 0) {
//        sum += S.top();
//        S.pop();
//    }
//
//    cout << sum;
//
//    return 0;
//}

//// BOJ 1158 요세푸스
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main(void) {
//
//    int N, K;
//    cin >> N >> K;
//
//    list<int> L;
//
//    for(int i=1;i<N+1;i++)
//        L.push_back(i);
//
//    auto pl = L.begin();
//
//    int cnt = 1;
//    int pc = 0;
//
//    cout << *L.end() << "\n";
//    cout << "<";
//    while(pc < N) {
//        if(cnt == K) {
//            pc++;
//            cout << *pl;
//            if(pc == N) {
//                cout << ">";
//                break;
//            }
//            else
//                cout << ", ";
//
//            cout << "\n" << "L.end() : " << *(--L.end()) << "\n";
//            if(pl == --L.end()) {
//                L.erase(pl);
//                pl = L.begin();
//            }
//            else
//                pl = L.erase(pl);
//            cnt = 1;
//        }
//        else {
//            if(pl == --L.end()) {
//                pl = L.begin();
//            }
//            else
//                pl++;
//            cnt++;
//        }
//
//    }
//
//    return 0;
//}

// BOJ 1874 스택 수열
//#include <iostream>
//#include <stack>
//#include <list>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    int *nums = new int[n];
//    stack<int> full;
//    stack<int> emp;
//    char seq[200001];
//    int ps = 0;
//    int pn = 0;
//    int cur = 0;
//    int tmp;
//    bool isNo = false;
//
//    for(int i=0;i<n;i++) {
//        full.push(n-i);
//        cin >> nums[i];
//    }
//
//    while(pn < n) {
//
//        if(cur > nums[pn]) {
//            if(emp.top() != nums[pn]) {
//                isNo = true;
//                break;
//            } else {
//                cur = nums[pn++];
//                seq[ps++] = '-';
//                emp.pop();
////                cout << "cur : " << cur << "\n";
//            }
//        } else if(cur < nums[pn]) {
//            tmp = full.top();
//            full.pop();
//            emp.push(tmp);
//            seq[ps++] = '+';
//
//            if(emp.top() == nums[pn]) {
//                cur = nums[pn++];
//                seq[ps++] = '-';
//                emp.pop();
////                cout << "cur : " << cur << "\n";
//            }
//        }
//    }
//
//    if(isNo) {
//        cout << "NO";
//    } else {
//        for(int i=0;i<ps;i++) {
//            cout << seq[i] << "\n";
//        }
//    }
//
//    delete []nums;
//    return 0;
//}

/* 스택 수열 <풀이노트>

스택 2개, n부터 1까지 찬 수열, 빈 수열

cur = 0 // 마지막으로 pop() 된 수열 값
ps = 0 (수열 인덱스)

cur > nums[ps] 이면 새 수열에서 pop -> 이때 둘이 nums[ps]와 pop한 값 다르면 NO -> 같으면 ps++
cur < nums[ps] 이면 새 수열에 push -> nums[ps]와 top 비교 -> 같으면 cur 교체 ps++ -> 다르면 아무일도x

+, - 문자 저장할 배열 최대 크기 20만, push pop(2가지 경우) x n 최대 수(100,000)

아니 C++ 동적할당 new int(n) 해서 계속 오류난거였네 어느 블로그에서 그래가지고 잘못쓰고있었네..

*/

// BOJ 2493 탑
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//typedef struct TagHiSet {
//    int h;
//    int idx;
//}hs;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//
//    stack<hs> tops;
//    stack<hs> receive;
//
//    cin >> N;
//    int heights[500000];
//    int results[500000] = {0, };
//
//    for(int i=0;i<N;i++) {
//        cin >> heights[i];
//        hs s;
//        s.h = heights[i];
//        s.idx = i;
//        tops.push(s);
//    }
//
//    // 최초 1회
//    receive.push(tops.top());
//    tops.pop();
//
//    while(tops.size() > 0) {
//        if(receive.size() == 0) {
//            receive.push(tops.top());
//            tops.pop();
//        }
//        else if(tops.top().h > receive.top().h) {
//            results[receive.top().idx] = tops.size();
//            receive.pop();
//        } else {
//            receive.push(tops.top());
//            tops.pop();
//        }
//    }
//
//    for(int i=0;i<N;i++) {
//        cout << results[i] << " ";
//    }
//
//    return 0;
//}

/* 탑 <풀이노트>

N개 높이 서로 다른 탑, ( N 50만 이하, 각 탑 높이는 최대 백억)

n1, n2, n3, ... ni 로 나열되고
맨 오른쪽서부터 왼쪽으로 레이저 발싸.
쏜 친구 높이보다 최초로 큰 놈이 수신. 그 놈 위치 적기(왼쪽부터 인덱스 1) (수신 하는 곳 없으면 0)

스택에 푸시하며 받는다. 만들어지는게 stack<int> tops

top부터 tops에서 팝해서 새로운 스택(stack<int> receive)에 푸시
단 다음과 과정을 거침 ( 맨 처음은 비교 대상이 없으니 예외로 걍 푸시 )
1. receive의 top과 비교, 만약 tops의 top이 더 크면 receive top을 팝함. 더 크지 않을 때까지(혹은 바닥일때까지) 반복.
2. tops.size() == 0이면 종료

*/
