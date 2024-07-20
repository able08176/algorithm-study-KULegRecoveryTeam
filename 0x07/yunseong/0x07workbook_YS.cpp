// BOJ 1021 회전하는 큐
//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N, M;
//    cin >> N >> M;
//
//    int *nums = new int[M];
//    deque<int> DQ;
//
//    for(int i=N;i>0;i--)
//        DQ.push_front(i);
//
//    for(int i=0;i<M;i++)
//        cin >> nums[i];
//
//    auto l = DQ.begin();
//    auto r = DQ.begin();
//
//    int pn = 0;
//    int cnt = 0;
//    while(pn < M) {
//        if(*l == nums[pn] || *r == nums[pn]) {
//            if(*l == nums[pn])
//                r = l;
//            else
//                l = r;
//
//            if(*l == DQ.back())
//            {
//                r = DQ.begin();
//                DQ.erase(l);
//                l = r;
//            } else {
//                l = DQ.erase(l);
//                r = l;
//            }
//
//            pn++;
////            cout << "\n--------\n";
//        } else {
//            if(*l == DQ.back())
//                l = DQ.begin();
//            else
//                l++;
//
//            if(r == DQ.begin())
//                r = DQ.begin() + DQ.size() - 1;
//            else
//                r--;
//
////            for(auto it : DQ)
////                cout << it << ' ';
////            cout << "\n";
////            for(int i=1;i<*r;i++)
////                cout << "  ";
////            cout << *r << "\n";
//
//            cnt++;
//        }
//    }
//
//    cout << cnt;
//
//    delete []nums;
//}

/* 회전하는 큐 <풀이노트>

l = '2번 연산' 시 변하는 head의 위치
r = '3번 연산' 시 변하는 head의 위치

head로부터 포인터 l, r을 출발시킨다.
l, r중 하나라도 뽑아내려고 하는 원소에 도달하면
해당 위치의 원소를 뽑아내고, 해당 위치 원소 다음 원소가 새로운 head가 되며, l, r을 그곳으로 다시 모은다.

다 뽑아낼 때까지 반복하며, l, r이 움직일 때마다 cnt++ 해준다.

반복이 끝나면 cnt를 출력한다.

*/

// BOJ 5430 AC
//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int main(void) {
//
//    int T;
//    string op;
//    string nothin;
//    int po; // pointer for op
//    int n;
//    bool isR;
//    bool isError;
//
//    cin >> T;
//
//    for(int t=0;t<T;t++) {
//        isR = false;
//        isError = false;
//        po = 0;
//        deque<int> DQ;
//        int *arr;
//
//        cin >> op;
//        cin >> n;
//
//        if(n==0) {
//            cin >> nothin;
//        } else if(n > 0) {
//            arr = new int[n];
//
//            cin.ignore();
//
//            if(n==1) {
//                scanf("[%d]", &arr[0]);
//            } else {
//                scanf("[%d,", &arr[0]);
//                for(int i=1;i<n-1;i++)
//                    scanf("%d,", &arr[i]);
//                scanf("%d]", &arr[n-1]);
//            }
//
//            for(int i=0;i<n;i++)
//                DQ.push_back(arr[i]);
//        }
//
//        while(op[po] != '\0') {
//            if(op[po] == 'R') {
//                if(isR)
//                    isR = false;
//                else
//                    isR = true;
//            } else if(op[po] == 'D') {
//                if(DQ.size() == 0)
//                {
//                    cout << "error\n";
//                    isError = true;
//                    break;
//                }
//
//                if(isR)
//                    DQ.pop_back();
//                else
//                    DQ.pop_front();
//            }
//
//            po++;
//        }
//
//        if(!isError) {
//            cout << "[";
//
//            if(DQ.size() > 0) {
//                auto pd = DQ.begin(); // pointer of DQ
//
//                if(isR) {
//                    pd = DQ.begin() + DQ.size() - 1;
//
//                    for(;pd != DQ.begin();pd--) {
//                        cout << *pd << ',';
//                    }
//
//                    cout << *pd;
//                } else {
//                    for(;pd != --DQ.end(); pd++) {
//                        cout << *pd << ',';
//                    }
//
//                    cout << *pd;
//                }
//            }
//
//            cout << "]\n";
//        }
//
//        if(n != 0)
//            delete []arr;
//    }
//
//    return 0;
//}

/* AC <풀이노트>

현재 역방향 상태(R)인지 순방향인지 기억하는 변수(flag) 두기

역방향 상태면 pop_back()
순방향 상태면 pop_front()

마지막에 출력시

역방향 상태면 뒤부터 출력하고
아니면 앞부터 ㅇㅇ

*/
