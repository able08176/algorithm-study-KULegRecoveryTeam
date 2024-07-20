// BOJ 1021 ȸ���ϴ� ť
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

/* ȸ���ϴ� ť <Ǯ�̳�Ʈ>

l = '2�� ����' �� ���ϴ� head�� ��ġ
r = '3�� ����' �� ���ϴ� head�� ��ġ

head�κ��� ������ l, r�� ��߽�Ų��.
l, r�� �ϳ��� �̾Ƴ����� �ϴ� ���ҿ� �����ϸ�
�ش� ��ġ�� ���Ҹ� �̾Ƴ���, �ش� ��ġ ���� ���� ���Ұ� ���ο� head�� �Ǹ�, l, r�� �װ����� �ٽ� ������.

�� �̾Ƴ� ������ �ݺ��ϸ�, l, r�� ������ ������ cnt++ ���ش�.

�ݺ��� ������ cnt�� ����Ѵ�.

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

/* AC <Ǯ�̳�Ʈ>

���� ������ ����(R)���� ���������� ����ϴ� ����(flag) �α�

������ ���¸� pop_back()
������ ���¸� pop_front()

�������� ��½�

������ ���¸� �ں��� ����ϰ�
�ƴϸ� �պ��� ����

*/
