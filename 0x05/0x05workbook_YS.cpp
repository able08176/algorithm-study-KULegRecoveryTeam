//���ǿ��� �迭 ���� �����϶�� �Ѱ�
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


//BOJ 10828 ����
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

//BOJ 54767 ����
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

//// BOJ 1158 �似Ǫ��
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

// BOJ 1874 ���� ����
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

/* ���� ���� <Ǯ�̳�Ʈ>

���� 2��, n���� 1���� �� ����, �� ����

cur = 0 // ���������� pop() �� ���� ��
ps = 0 (���� �ε���)

cur > nums[ps] �̸� �� �������� pop -> �̶� ���� nums[ps]�� pop�� �� �ٸ��� NO -> ������ ps++
cur < nums[ps] �̸� �� ������ push -> nums[ps]�� top �� -> ������ cur ��ü ps++ -> �ٸ��� �ƹ��ϵ�x

+, - ���� ������ �迭 �ִ� ũ�� 20��, push pop(2���� ���) x n �ִ� ��(100,000)

�ƴ� C++ �����Ҵ� new int(n) �ؼ� ��� �������ſ��� ��� ��α׿��� �׷������� �߸������־���..

*/

// BOJ 2493 ž
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
//    // ���� 1ȸ
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

/* ž <Ǯ�̳�Ʈ>

N�� ���� ���� �ٸ� ž, ( N 50�� ����, �� ž ���̴� �ִ� ���)

n1, n2, n3, ... ni �� �����ǰ�
�� �����ʼ����� �������� ������ �߽�.
�� ģ�� ���̺��� ���ʷ� ū ���� ����. �� �� ��ġ ����(���ʺ��� �ε��� 1) (���� �ϴ� �� ������ 0)

���ÿ� Ǫ���ϸ� �޴´�. ��������°� stack<int> tops

top���� tops���� ���ؼ� ���ο� ����(stack<int> receive)�� Ǫ��
�� ������ ������ ��ħ ( �� ó���� �� ����� ������ ���ܷ� �� Ǫ�� )
1. receive�� top�� ��, ���� tops�� top�� �� ũ�� receive top�� ����. �� ũ�� ���� ������(Ȥ�� �ٴ��϶�����) �ݺ�.
2. tops.size() == 0�̸� ����

*/
