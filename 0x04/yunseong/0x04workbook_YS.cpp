// test
//#include <bits/stdc++.h>
//using namespace std;
//
//const int MX = 1000005;
//int dat[MX], pre[MX], nxt[MX];
//int unused = 1;
//
//void insert(int addr, int num){ // addr µÚ
//    int cur = unused;
//    unused++;
//
//    dat[cur] = num;
//    pre[cur] = addr;
//    nxt[cur] = nxt[addr];
//    nxt[addr] = cur;
//    if(nxt[cur] != -1)
//        pre[nxt[cur]] = cur;
//}
//
//void erase(int addr){
//    int next_addr = nxt[addr];
//    int prev_addr = pre[addr];
//
//    if(next_addr != -1) pre[next_addr] = prev_addr;
//    nxt[prev_addr] = next_addr;
//}
//
//void traverse(){
//  int cur = nxt[0];
//  while(cur != -1){
//    cout << dat[cur] << ' ';
//    cur = nxt[cur];
//  }
//  cout << "\n\n";
//}
//
//void insert_test(){
//  cout << "****** insert_test *****\n";
//  insert(0, 10); // 10(address=1)
//  traverse();
//  insert(0, 30); // 30(address=2) 10
//  traverse();
//  insert(2, 40); // 30 40(address=3) 10
//  traverse();
//  insert(1, 20); // 30 40 10 20(address=4)
//  traverse();
//  insert(4, 70); // 30 40 10 20 70(address=5)
//  traverse();
//}
//
//void erase_test(){
//  cout << "****** erase_test *****\n";
//  erase(1); // 30 40 20 70
//  traverse();
//  erase(2); // 40 20 70
//  traverse();
//  erase(4); // 40 70
//  traverse();
//  erase(5); // 40
//  traverse();
//}
//
//int main(void) {
//  fill(pre, pre+MX, -1);
//  fill(nxt, nxt+MX, -1);
//  insert_test();
//  erase_test();
//}

// BOJ 1406 에디터
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    string c;
//    int M;
//    cin >> c;
//    cin >> M;
//
//    list<char> L = {'S'};
//    list<char>::iterator lp = L.end();
//
//    int cp=0;
//    while(c[cp] != '\0') {
//        L.insert(lp, c[cp]);
//        cp++;
//    }
//
//    for(int i=0;i<M;i++) {
//        char op1;
//        char op2;
//
//        cin >> op1;
//
//        if(op1 == 'P')
//            cin >> op2;
//
//        switch(op1) {
//
//            case 'L':
//                lp--;
//                if(lp == L.begin())
//                    lp++;
//                break;
//            case 'D':
//                if(lp != L.end())
//                    lp++;
//                break;
//            case 'B':
//                lp--;
//                if(lp != L.begin()) {
//                    lp = L.erase(lp);
//                } else lp++;
//                break;
//            case 'P':
//                L.insert(lp, op2);
//                break;
//        }
//    }
//
//    for(auto it : L)
//    {
//        if(it != 'S')
//            cout << it;
//    }
//    return 0;
//}

// BOJ 5397 키로거
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int TC;
//    cin >> TC;
//
//
//    while(TC>0) {
//        string keylog;
//        cin >> keylog;
//
//        list<char> pw = {'$', '@'};
//        auto ppw = pw.begin();
//        ppw++;
//        int pkl = 0;
//        while(keylog[pkl] != '\0') {
//            if(keylog[pkl] == '<') {
//                if(*ppw != '$') {
//                    ppw--;
//                    if(*ppw == '$')
//                        ppw++;
//                }
//            }
//            else if(keylog[pkl] == '>') {
//                if(*ppw != '@')
//                    ppw++;
//            }
//            else if(keylog[pkl] == '-') {
//                if(*ppw != '$') {
//                    ppw--;
//                    if(*ppw == '$')
//                        ppw++;
//                    else
//                        ppw = pw.erase(ppw);
//                }
//            }
//            else {
//                pw.insert(ppw, keylog[pkl]);
//            }
//
////            for(auto it : pw) {
////                cout << it;
////            }
////            cout << "cursor = " << *ppw;
////            cout << '\n';
//
//            pkl++;
//        }
//
//        for(auto it : pw) {
//            if(it != '$' && it != '@')
//                cout << it;
//        }
//        cout << '\n';
//
//        TC--;
//    }
//
//    return 0;
//}

// BOJ 1158 요세푸스
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    list<int> L;

    for (int i = 1; i < N + 1; i++)
        L.push_back(i);

    auto pl = L.begin();

    int cnt = 1;
    int pc = 0;

    cout << "<";
    while (pc < N) {
        if (pl == L.end()) {
            pl = L.begin();
        }
        if (cnt == K) {
            pc++;
            cout << *pl;
            if (pc == N) {
                cout << ">";
                break;
            } else
                cout << ", ";

            if (pl == L.end()) {
                L.erase(pl);
                pl = L.begin();
            } else
                pl = L.erase(pl);

            cnt = 1;
        } else {
            if (pl == L.end()) {
                pl = L.begin();
            } else {
                pl++;
                cnt++;
            }
        }
    }

    return 0;

    // BOJ 1158 윤성이 코드에서 체크해볼만한 점이 많았음.
    // 윤성이 코드에서의 주요 이슈는 234, 242줄에서
    // iterator가 마지막 값을 가리키는 지 검사하는 코드를 어떻게 작성하냐에서 발생함.

    // 코드를 pl == --L.end() or *pl == L.back()으로 작성하면 정상작동하지만,
    // pl == end()와 같이 작성하면 에러 발생.
    // 그 이유는 227줄에서 발생.

    // cnt가 2이고 iterator가 가장 마지막 원소를 가리키고 있는 상황이면,
    // while문을 한번 더 돌았을 때 cnt가 3이 되고 iterator는 end를 가리키게 됨.
    // 이 때, 다시 while문을 돌면 227줄에서 end를 가리키는 iterator를 참조하게 되므로 에러 발생!

    // 코드를 pl == --L.end() or *pl == L.back()으로 작성하고 cnt 증가를 적정한 곳에서 실행해주면
    // iterator가 end를 가리키는 상황 자체가 발생하지 않음.
    // 위 코드는 조건식을 변경하지는 않고(pl == L.end()으로 냅둠), 227줄에서 pl을 참조할 때
    // 그 전에 end를 가리키는 지 검사하여 begin을 가리키도록 수정하여 해결함.

    // 코드 자체가 N, k, pc, cnt, L(Linked list)의 많은 변수를 가지고 있고,
    // 이들을 동기화시키는 식으로 운용되는데, 그 과정이 복잡하여 에러 발생 확률이 높았음.
    // 예를 들어, 위와 같이 pl == L.end()로 조건을 검사할 경우에는
    // iterator를 end에서 begin으로 바꿀 때 cnt를 증가시키면 안되지만,
    // 조건을 pl == --L.end() or *pl == L.back()으로 검사할 경우에는
    // iterator가 마지막 원소에서 begin(첫번째 원소)을 가리키게 되므로 무조건 cnt를 증가시켜줘야 함.

    // 위와 같이, 여러 변수를 서로 동기화시키는 식으로 코드를 작성할 때에는
    // 값이 서로 동기화되는 과정을 정교하게 생각해보는 태도가 요구됨.
    // by JAEYOUNG PARK
}
