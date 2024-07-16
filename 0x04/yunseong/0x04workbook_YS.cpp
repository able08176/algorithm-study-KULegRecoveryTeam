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
//            if(*pl == L.back()) {
//                L.erase(pl);
//                pl = L.begin();
//            }
//            else
//                pl = L.erase(pl);
//
//            cnt = 1;
//        }
//        else {
//            if(*pl == L.back()) {
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
