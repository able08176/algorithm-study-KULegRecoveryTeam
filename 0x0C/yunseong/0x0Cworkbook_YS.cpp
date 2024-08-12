// BOJ 15649 N과 M (1)
//#include <iostream>
//
//using namespace std;
//
//int N, M;
//int arr[10];
//bool vis[10];
//
//void bt(int cnt) {
//    if(cnt == M) {
//        for(int i=0;i<M;i++) {
//            cout << arr[i] << ' ';
//        }
//        cout << "\n";
//        return;
//    }
//
//    for(int i=1;i<=N;i++) {
//        if(!vis[i]) {
//            arr[cnt] = i;
//            vis[i] = 1; // 이 깊이를 들어가기 전에 vis 처리
//            bt(cnt+1); // 깊이로 들어가기
//            vis[i] = 0; // 해당 깊이를 들어갓다 나왓기에 vis 미방문 처리
//        }
//    }
//
//}
//
//int main()
//{
//    cin >> N >> M;
//    bt(0);
//
//    return 0;
//}

// BOJ 9663 N-Queen
//#include <iostream>
//
//using namespace std;
//
//int n;
//int cnt;
//bool vis[15];
//
//void bt(int r, int **board) {
//    if(r == n-1) {
//        for(int i=0;i<n;i++) {
//            for(int j=0;j<n;j++)
//                cout << board[i][j] << ' ';
//            cout << "\n";
//        }
//        cout << "\nvis : ";
//        for(int i=0;i<n;i++) {
//            cout << vis[i] << ' ';
//        }
//        cout << "\n";
//
//        for(int i=0;i<n;i++) {
//            if(vis[i] == 0 && board[r][i] == 0)
//                cnt++;
//        }
//        return;
//    } else {
//        for(int i=0;i<n;i++) {
//
//            if(vis[i] == 0 && board[r][i] == 0) {
//
//                vis[i] = 1;
//                board[r][i] = 2;
//
//                int nx = r;
//                int ny = i;
//                while(true) {
//                    nx -= 1;
//                    ny -= 1;
//                    if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) break;
//                    board[nx][ny] = 1;
//                }
//                nx = r;
//                ny = i;
//                while(true) {
//                    nx += 1;
//                    ny += 1;
//                    if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) break;
//                    board[nx][ny] = 1;
//                }
//                nx = r;
//                ny = i;
//                while(true) {
//                    nx -= 1;
//                    ny += 1;
//                    if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) break;
//                    board[nx][ny] = 1;
//                }
//                nx = r;
//                ny = i;
//                while(true) {
//                    nx += 1;
//                    ny -= 1;
//                    if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) break;
//                    board[nx][ny] = 1;
//                }
//
//                bt(r+1, board);
//
//                nx = r;
//                ny = i;
//                while(true) {
//                    nx -= 1;
//                    ny -= 1;
//                    if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) break;
//                    board[nx][ny] = 0;
//                }
//                nx = r;
//                ny = i;
//                while(true) {
//                    nx += 1;
//                    ny += 1;
//                    if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) break;
//                    board[nx][ny] = 0;
//                }
//                nx = r;
//                ny = i;
//                while(true) {
//                    nx -= 1;
//                    ny += 1;
//                    if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) break;
//                    board[nx][ny] = 0;
//                }
//                nx = r;
//                ny = i;
//                while(true) {
//                    nx += 1;
//                    ny -= 1;
//                    if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1) break;
//                    board[nx][ny] = 0;
//                }
//
//                board[r][i] = 0;
//                vis[i] = 0;
//            }
//        }
//    }
//
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n;
//
//    int **b = (int**)malloc(sizeof(int*)*n);
//    for(int j=0;j<n;j++)
//        b[j] = (int*)calloc(n, sizeof(int));
//    bt(0, b);
//
//    cout << cnt;
//
//    return 0;
//}

// 위 코드 안됌. 이유는 모르겠음..

// BOJ 1182 부분수열의 합
//#include <iostream>
//
//using namespace std;
//
//int sum, cnt;
//int n, S;
//int seq[20];
//
//void bt(int s, int t) {
//    if(s == n) {
//        if(t == S) cnt++;
//        return;
//    }
//
//    bt(s+1, t);
//    bt(s+1, t+seq[s]);
//
//}
//
//int main(void) {
//    cin >> n >> S;
//    for(int i=0;i<n;i++)
//        cin >> seq[i];
//    bt(0, 0);
//    if(S == 0) cnt--; // 전부 안골랏을때 0인데, s=0인경우는 해당되버리니까 그경우엔 1빼줌
//    cout << cnt;
//    return 0;
//}

// BOJ 15650 N과 M(2)
//#include <iostream>
//
//using namespace std;
//
//int n,m;
//int vis[10];
//int arr[10];
//
//void bt(int s, int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    for(int i=s;i<=n;i++) {
//        if(!vis[i]) {
//            vis[i] = 1;
//            arr[c] = i;
//            bt(i+1, c+1);
//            vis[i] = 0;
//        }
//    }
//
//}
//
//int main(void) {
//    cin >> n >> m;
//    bt(1, 0);
//
//    return 0;
//}

// BOJ 15651 N과 M(3)
//#include <iostream>
//
//using namespace std;
//
//int n,m;
//int vis[10];
//int arr[10];
//
//void bt(int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    for(int i=1;i<=n;i++) {
//        arr[c] = i;
//        bt(c+1);
//    }
//
//}
//
//int main(void) {
//    cin >> n >> m;
//    bt(0);
//
//    return 0;
//}

// BOJ 15652 N과 M(4)
//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[10];
//int vis[10];
//
//void bt(int s, int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    for(int i=s;i<=n;i++) {
//        arr[c] = i;
//        bt(i, c+1);
//    }
//
//}
//
//int main(void) {
//    cin >> n >> m;
//    bt(1, 0);
//
//    return 0;
//}

// BOJ 15654 N과 M(5)
//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[10];
//int vis[10];
//int seq[10];
//
//void bt(int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    for(int i=0;i<n;i++) {
//        if(!vis[i]) {
//            vis[i] = 1;
//            arr[c] = seq[i];
//            bt(c+1);
//            vis[i] = 0;
//        }
//    }
//}
//
//void Merge(int *a, int p, int q, int r) {
//    int *buf;
//    int i, j, b;
//    buf = (int*)malloc(sizeof(int)*(r-p+1));
//    i = p; j = q+1; b = 0;
//
//    while(i<=q && j<=r) {
//        if(a[i] > a[j]) buf[b++] = a[j++];
//        else buf[b++] = a[i++];
//    }
//
//    while(i<=q) {
//        buf[b++] = a[i++];
//    }
//
//    while(j<=r) {
//        buf[b++] = a[j++];
//    }
//
//    i=p; b=0;
//    while(i<=r) {
//        a[i++] = buf[b++];
//    }
//
//    free(buf);
//}
//
//void merge_sort(int *a, int p, int r) {
//    if(p < r) {
//        int q = p + (r - p)/2;
//        merge_sort(a, p, q);
//        merge_sort(a, q+1, r);
//        Merge(a, p, q, r);
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    for(int i=0;i<n;i++)
//        cin >> seq[i];
//
//    merge_sort(seq, 0, n-1);
//    bt(0);
//
//    return 0;
//}

/*
머지소트는 외워뒀습니다.
*/

// BOJ 15654 N과 M(6)
//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[10];
//int vis[10];
//int seq[10];
//
//void bt(int s, int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    for(int i=s;i<n;i++) {
//        if(!vis[i]) {
//            vis[i] = 1;
//            arr[c] = seq[i];
//            bt(i+1, c+1);
//            vis[i] = 0;
//        }
//    }
//}
//
//void Merge(int *a, int p, int q, int r) {
//    int *buf;
//    int i, j, b;
//    buf = (int*)malloc(sizeof(int)*(r-p+1));
//    i = p; j = q+1; b = 0;
//
//    while(i<=q && j<=r) {
//        if(a[i] > a[j]) buf[b++] = a[j++];
//        else buf[b++] = a[i++];
//    }
//
//    while(i<=q) {
//        buf[b++] = a[i++];
//    }
//
//    while(j<=r) {
//        buf[b++] = a[j++];
//    }
//
//    i=p; b=0;
//    while(i<=r) {
//        a[i++] = buf[b++];
//    }
//
//    free(buf);
//}
//
//void merge_sort(int *a, int p, int r) {
//    if(p < r) {
//        int q = p + (r - p)/2;
//        merge_sort(a, p, q);
//        merge_sort(a, q+1, r);
//        Merge(a, p, q, r);
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    for(int i=0;i<n;i++)
//        cin >> seq[i];
//
//    merge_sort(seq, 0, n-1);
//    bt(0, 0);
//
//    return 0;
//}

// BOJ 15656 N과 M(7)
//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[10];
//int vis[10];
//int seq[10];
//
//void bt(int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    for(int i=0;i<n;i++) {
//        arr[c] = seq[i];
//        bt(c+1);
//    }
//}
//
//void Merge(int *a, int p, int q, int r) {
//    int *buf;
//    int i, j, b;
//    buf = (int*)malloc(sizeof(int)*(r-p+1));
//    i = p; j = q+1; b = 0;
//
//    while(i<=q && j<=r) {
//        if(a[i] > a[j]) buf[b++] = a[j++];
//        else buf[b++] = a[i++];
//    }
//
//    while(i<=q) {
//        buf[b++] = a[i++];
//    }
//
//    while(j<=r) {
//        buf[b++] = a[j++];
//    }
//
//    i=p; b=0;
//    while(i<=r) {
//        a[i++] = buf[b++];
//    }
//
//    free(buf);
//}
//
//void merge_sort(int *a, int p, int r) {
//    if(p < r) {
//        int q = p + (r - p)/2;
//        merge_sort(a, p, q);
//        merge_sort(a, q+1, r);
//        Merge(a, p, q, r);
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    for(int i=0;i<n;i++)
//        cin >> seq[i];
//
//    merge_sort(seq, 0, n-1);
//    bt(0);
//
//    return 0;
//}

// BOJ 15656 N과 M(8)
//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[10];
//int vis[10];
//int seq[10];
//
//void bt(int s, int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    for(int i=s;i<n;i++) {
//        arr[c] = seq[i];
//        bt(i, c+1);
//    }
//}
//
//void Merge(int *a, int p, int q, int r) {
//    int *buf;
//    int i, j, b;
//    buf = (int*)malloc(sizeof(int)*(r-p+1));
//    i = p; j = q+1; b = 0;
//
//    while(i<=q && j<=r) {
//        if(a[i] > a[j]) buf[b++] = a[j++];
//        else buf[b++] = a[i++];
//    }
//
//    while(i<=q) {
//        buf[b++] = a[i++];
//    }
//
//    while(j<=r) {
//        buf[b++] = a[j++];
//    }
//
//    i=p; b=0;
//    while(i<=r) {
//        a[i++] = buf[b++];
//    }
//
//    free(buf);
//}
//
//void merge_sort(int *a, int p, int r) {
//    if(p < r) {
//        int q = p + (r - p)/2;
//        merge_sort(a, p, q);
//        merge_sort(a, q+1, r);
//        Merge(a, p, q, r);
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    for(int i=0;i<n;i++)
//        cin >> seq[i];
//
//    merge_sort(seq, 0, n-1);
//    bt(0, 0);
//
//    return 0;
//}

// BOJ 15656 N과 M(9)
//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[10];
//int vis[10];
//int seq[10];
//
//void bt(int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    for(int i=0;i<n;i++) {
//        if(!vis[i] && arr[c] != seq[i]) { // 처음에 이거만 추가했는데 맞왜틀이었음
//            vis[i] = 1;
//            arr[c] = seq[i];
//            bt(c+1);
//            if(arr[c+1] != 0) // 추후에 이 조건 처리를 추가하니 맞았음... 뭐지? 왜 맞았지?
//                arr[c+1] = 0;
//            vis[i] = 0;
//        }
//    }
//
//}
//
//void Merge(int *a, int p, int q, int r) {
//    int *buf;
//    int i, j, b;
//    buf = (int*)malloc(sizeof(int)*(r-p+1));
//    i = p; j = q+1; b = 0;
//
//    while(i<=q && j<=r) {
//        if(a[i] >= a[j]) buf[b++] = a[j++];
//        else buf[b++] = a[i++];
//    }
//
//    while(i<=q) {
//        buf[b++] = a[i++];
//    }
//
//    while(j<=r) {
//        buf[b++] = a[j++];
//    }
//
//    i=p; b=0;
//    while(i<=r) {
//        a[i++] = buf[b++];
//    }
//
//    free(buf);
//}
//
//void merge_sort(int *a, int p, int r) {
//    if(p < r) {
//        int q = p + (r - p)/2;
//        merge_sort(a, p, q);
//        merge_sort(a, q+1, r);
//        Merge(a, p, q, r);
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    for(int i=0;i<n;i++)
//        cin >> seq[i];
//
//    merge_sort(seq, 0, n-1);
//    bt(0);
//
//    return 0;
//}

// BOJ 15656 N과 M(10)
//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[10];
//int vis[10];
//int seq[10];
//
//void bt(int s, int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    int tmp = 0;
//    for(int i=0;i<n;i++) {
//        if(!vis[i] && tmp != seq[i]) {
//            vis[i] = 1;
//            arr[c] = seq[i];
//            tmp = arr[c];
//            bt(i+1, c+1);
//            vis[i] = 0;
//        }
//    }
//
//}
//
//void Merge(int *a, int p, int q, int r) {
//    int *buf;
//    int i, j, b;
//    buf = (int*)malloc(sizeof(int)*(r-p+1));
//    i = p; j = q+1; b = 0;
//
//    while(i<=q && j<=r) {
//        if(a[i] >= a[j]) buf[b++] = a[j++];
//        else buf[b++] = a[i++];
//    }
//
//    while(i<=q) {
//        buf[b++] = a[i++];
//    }
//
//    while(j<=r) {
//        buf[b++] = a[j++];
//    }
//
//    i=p; b=0;
//    while(i<=r) {
//        a[i++] = buf[b++];
//    }
//
//    free(buf);
//}
//
//void merge_sort(int *a, int p, int r) {
//    if(p < r) {
//        int q = p + (r - p)/2;
//        merge_sort(a, p, q);
//        merge_sort(a, q+1, r);
//        Merge(a, p, q, r);
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    for(int i=0;i<n;i++)
//        cin >> seq[i];
//
//    merge_sort(seq, 0, n-1);
//    bt(0, 0);
//
//    return 0;
//}

// BOJ 15656 N과 M(11)
//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[10];
//int vis[10];
//int seq[10];
//
//void bt(int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    int tmp = 0;
//    for(int i=0;i<n;i++) {
//        if(tmp != seq[i]) {
//            arr[c] = seq[i];
//            tmp = arr[c];
//            bt(c+1);
//        }
//    }
//
//}
//
//void Merge(int *a, int p, int q, int r) {
//    int *buf;
//    int i, j, b;
//    buf = (int*)malloc(sizeof(int)*(r-p+1));
//    i = p; j = q+1; b = 0;
//
//    while(i<=q && j<=r) {
//        if(a[i] >= a[j]) buf[b++] = a[j++];
//        else buf[b++] = a[i++];
//    }
//
//    while(i<=q) {
//        buf[b++] = a[i++];
//    }
//
//    while(j<=r) {
//        buf[b++] = a[j++];
//    }
//
//    i=p; b=0;
//    while(i<=r) {
//        a[i++] = buf[b++];
//    }
//
//    free(buf);
//}
//
//void merge_sort(int *a, int p, int r) {
//    if(p < r) {
//        int q = p + (r - p)/2;
//        merge_sort(a, p, q);
//        merge_sort(a, q+1, r);
//        Merge(a, p, q, r);
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    for(int i=0;i<n;i++)
//        cin >> seq[i];
//
//    merge_sort(seq, 0, n-1);
//    bt(0);
//
//    return 0;
//}

// BOJ 15656 N과 M(12)
//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int arr[10];
//int vis[10];
//int seq[10];
//
//void bt(int s, int c) {
//    if(c == m) {
//        for(int i=0;i<m;i++)
//            cout << arr[i] << ' ';
//        cout << "\n";
//        return;
//    }
//
//    int tmp = 0;
//    for(int i=s;i<n;i++) {
//        if(tmp != seq[i]) {
//            arr[c] = seq[i];
//            tmp = arr[c];
//            bt(i, c+1);
//        }
//    }
//
//}
//
//void Merge(int *a, int p, int q, int r) {
//    int *buf;
//    int i, j, b;
//    buf = (int*)malloc(sizeof(int)*(r-p+1));
//    i = p; j = q+1; b = 0;
//
//    while(i<=q && j<=r) {
//        if(a[i] >= a[j]) buf[b++] = a[j++];
//        else buf[b++] = a[i++];
//    }
//
//    while(i<=q) {
//        buf[b++] = a[i++];
//    }
//
//    while(j<=r) {
//        buf[b++] = a[j++];
//    }
//
//    i=p; b=0;
//    while(i<=r) {
//        a[i++] = buf[b++];
//    }
//
//    free(buf);
//}
//
//void merge_sort(int *a, int p, int r) {
//    if(p < r) {
//        int q = p + (r - p)/2;
//        merge_sort(a, p, q);
//        merge_sort(a, q+1, r);
//        Merge(a, p, q, r);
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    for(int i=0;i<n;i++)
//        cin >> seq[i];
//
//    merge_sort(seq, 0, n-1);
//    bt(0, 0);
//
//    return 0;
//}

// BOJ 6603 로또
//#include <iostream>
//
//using namespace std;
//
//int arr[6];
//int S[13];
//bool vis[15];
//int k;
//
//
//void bt(int s, int c) {
//    if(c==6) {
//        for(int i=0;i<6;i++)
//            cout << arr[i] << ' ';
//        cout << '\n';
//        return;
//    }
//
//    for(int i=s;i<k;i++) {
//        if(!vis[i]) {
//            vis[i] = 1;
//            arr[c]=S[i];
//            bt(i+1, c+1);
//            vis[i] = 0;
//        }
//    }
//
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    while(true) {
//        cin >> k;
//
//        if(!k)
//            break;
//
//        for(int i=0;i<k;i++)
//            cin >> S[i];
//
//        bt(0, 0);
//        cout << "\n";
//    }
//
//    return 0;
//}

// BOJ 1941 소문난 칠공주
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//
//bool mark[25];
//int cnt;
//bool cr[5][5]; // 'c'lass'r'oom
//bool cmap[5][5];
//bool vis[5][5];
//
//int main(void) {
//
//    char c;
//    for(int i=0;i<5;i++) {
//        for(int j=0;j<5;j++) {
//            cin >> c;
//            if(c == 'Y')
//                cr[i][j] = 0;
//            else
//                cr[i][j] = 1;
//        }
//    }
//
//    for(int i=0;i<25;i++) {
//        if(i<7)
//            mark[i] = false;
//        else
//            mark[i] = true;
//    }
//
//    do {
//        queue<pair<int, int>> q;
//        bool cmap[5][5] = {0,};
//        bool vis[5][5] = {0,};
//
//        for(int i=0;i<25;i++) {
//            cmap[i / 5][i % 5] = !mark[i];
//            if(!mark[i] && q.empty()) {
//                q.push({i/5, i%5});
//                vis[i/5][i%5] = 1;
//            }
//        }
//
//        int seven = 0;
//        int asper = 0;
//
//        while(!q.empty()) {
//            pair<int, int> cur = q.front(); q.pop();
//
//            if(cmap[cur.first][cur.second])
//                seven++;
//            if(cr[cur.first][cur.second])
//                asper++;
//
//            for(int i=0;i<4;i++) {
//                int nx = cur.first+dx[i];
//                int ny = cur.second+dy[i];
//
//                if(nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
//                if(vis[nx][ny]) continue;
//                if(!cmap[nx][ny]) continue;
//
//                vis[nx][ny] = 1;
//                q.push({nx, ny});
//            }
//        }
//
//        if(seven == 7 && asper >= 4)
//            cnt++;
//
//    } while(next_permutation(mark, mark+25));
//
//    cout << cnt;
//
//    return 0;
//}

/* 소문난 칠공주 <풀이과정>

음.. 도저히 답안나와서 바킹독씨 풀이 봤습니다.
아 모든 경우를 next_permutation으로 돌려서 다 검사하는 방식일줄은...
예...

*/

// BOJ 16987 계란으로 계란치기
//#include <iostream>
//
//using namespace std;
//
//int n;
//int egg[10][2];
//int max_cnt = 0;
//
//void bt(int s, int c) {
//    if(s == n) {
//        if(c > max_cnt)
//            max_cnt = c;
//
//        return;
//    }
//
//    if(egg[s][0] <= 0) {
//        bt(s+1, c);
//        return;
//    }
//
//    if(n-c == 1)
//    {
//        if(c > max_cnt)
//            max_cnt = c;
//
//        return;
//    }
//
//
//    for(int i=0;i<n;i++) {
//        if(egg[i][0] > 0 && i != s) {
//            egg[s][0] -= egg[i][1];
//            egg[i][0] -= egg[s][1];
//
//            if(egg[s][0] <= 0 && egg[i][0] <= 0)
//                bt(s+1, c+2);
//            else if(egg[s][0] <= 0 || egg[i][0] <= 0)
//                bt(s+1, c+1);
//            else
//                bt(s+1, c);
//
//            egg[s][0] += egg[i][1];
//            egg[i][0] += egg[s][1];
//        }
//    }
//
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n;
//
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<2;j++)
//            cin >> egg[i][j];
//    }
//
//    bt(0, 0);
//
//    cout << max_cnt;
//
//    return 0;
//}

/* 계란으로 계란치기 <풀이과정>

모든 서로 깨는 경우의 수를 일일히 전수조사한다.
어쩌다보니 스파게티 코드가 되부렷는데...
아 이건 맞고도 찜찜허네..

*/

