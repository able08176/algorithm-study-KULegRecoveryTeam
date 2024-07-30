// BOJ 1926 �׸�
//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define X first
//#define Y second
//using namespace std;
//
//int vis[500][500];
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    int pic_cnt = 0; // # of pictures
//    int maxSize = 0; // biggest picture size
//
//    cin >> n >> m;
//
//    queue<pair<int, int>> colored;
//    int **dohwaji = new int*[n];
//    for(int i=0;i<n;i++)
//        dohwaji[i] = new int[m];
//
//
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            cin >> dohwaji[i][j];
//            if(dohwaji[i][j] == 1)
//                colored.push({i, j});
//        }
//    }
//
//    while(!colored.empty()) {
//        pair<int, int> sp = colored.front(); // sp is start point
//
//        if(!vis[sp.X][sp.Y]) {
//            vis[sp.X][sp.Y] = 1;
//            pic_cnt++;
//
//            int tmp = 1;
//            queue<pair<int, int>> BQ;
//
//            BQ.push({sp.X, sp.Y});
//
//            while(!BQ.empty()) {
//                pair<int, int> cur = BQ.front(); BQ.pop();
//
//                for(int i=0;i<4;i++) {
//                    int nx = cur.X + dx[i];
//                    int ny = cur.Y + dy[i];
//
//                    if(nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
//                    if(dohwaji[nx][ny] == 0) continue;
//                    if(vis[nx][ny]) continue;
//
//
//                    BQ.push({nx, ny});
//                    vis[nx][ny] = 1;
//                    tmp++;
//                }
//            }
//
//            if(tmp > maxSize)
//                maxSize = tmp;
//        }
//
//        colored.pop();
//    }
//
//    cout << pic_cnt << "\n";
//    cout << maxSize << "\n";
//
//
//
//    for(int i=0;i<n;i++)
//        delete[] dohwaji[i];
//
//    delete[] dohwaji;
//
//    return 0;
//}

/* �׸� <Ǯ�̰���>

1�� ��ǥ�� ���,
�ϳ� �� �湮�ϴµ�
visited ���¸� �׳� �Ѿ��
�ƴ϶�� pic_cnt++�ϰ� BFS.
BFS ��ġ�� ���� max�� ��.

*/

// BOJ 2178 �̷�
//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define X first
//#define Y second
//
//using namespace std;
//
//int vis[100][100];
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N, M;
//
//    cin >> N >> M;
//
//    string *miro = new string[N];
//
//    for(int i=0;i<N;i++)
//        cin >> miro[i];
//
//    bool isOut = false;
//
//    queue<pair<pair<int, int>, int>> BQ;
//
//    BQ.push({{0, 0}, 1});
//    vis[0][0] = 1;
//
//    while(!BQ.empty()) {
//
//        pair<pair<int, int>, int> cur = BQ.front(); BQ.pop();
//
//        for(int i=0;i<4;i++) {
//            int nx = cur.X.X + dx[i];
//            int ny = cur.X.Y + dy[i];
//            int nv = cur.Y + 1;
//
//            if(nx < 0 || ny < 0 || nx > N-1 || ny > M-1) continue;
//            if(miro[nx][ny] == '0') continue;
//            if(vis[nx][ny]) continue;
//
//            if(nx == N-1 && ny == M-1) {
//                isOut = true;
//                cout << nv;
//                break;
//            }
//
//            BQ.push({{nx, ny}, nv});
//            vis[nx][ny] = 1;
//        }
//
//        if(isOut)
//            break;
//    }
//
//    delete[] miro;
//
//    return 0;
//}

/* �� �����غ��� �׳� �̷ο��ٰ� �� ���� �Ǵ±���. ����
ť ������ ���... */

// BOJ 7576 �丶��
//#include <iostream>
//#include <vector>
//#include <queue>
//#define X first
//#define Y second
//
//using namespace std;
//
//int vis[1000][1000];
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int M, N; // [N][M]
//    int zeros = 0;
//    bool isEnd = false;
//
//    cin >> M >> N;
//
//    queue<pair<pair<int, int>, int>> Q;
//    int **farm = new int*[N];
//    for(int i=0;i<N;i++)
//        farm[i] = new int[M];
//
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<M;j++) {
//            cin >> farm[i][j];
//
//            if(farm[i][j] > 0) {
//                Q.push({{i, j}, 0});
//                vis[i][j] = 1;
//            }
//            else if(farm[i][j] == 0)
//                zeros++;
//        }
//    }
//
//    if(zeros == 0)
//        cout << 0;
//    else {
//        while(!Q.empty()) {
//            pair<pair<int, int>, int> cur = Q.front(); Q.pop();
//
//            for(int i=0;i<4;i++) {
//                int nx = cur.X.X + dx[i];
//                int ny = cur.X.Y + dy[i];
//                int nv = cur.Y + 1;
//
//                if(nx < 0 || ny < 0 || nx > N-1 || ny > M-1) continue;
//                if(farm[nx][ny] != 0) continue;
//                if(vis[nx][ny] == 1) continue;
//
//                zeros--;
//                if(zeros == 0)
//                {
//                    cout << nv;
//                    isEnd = true;
//                    break;
//                }
//
//                vis[nx][ny] = 1;
//                Q.push({{nx, ny}, nv});
//
//            }
//
//            if(isEnd)
//                break;
//        }
//
//        if(zeros > 0)
//            cout << -1;
//    }
//
//    for(int i=0;i<N;i++)
//        delete[] farm[i];
//    delete[] farm;
//
//    return 0;
//}


/* ��ŷ������ dist��� �Ÿ� �迭�� ���� �ΰ�
�� �������� 0, �ű⼭���� ���� +1�� �ϰ� �Ͽ� ��¥�� ����ϰ�
�������� ��ü ��ȸ���� �� ���� ���ߴ°� �� ���� ��¥�� �˻��ߴ�. */

// BOJ 4179 ��!
//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define X first
//#define Y second
//
//using namespace std;
//
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//
//int miro[1000][1000];
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int R, C;
//    char ip;
//
//    cin >> R >> C;
//
//   // 0 = can go, -1 = wall, -2 = fire
//
//    queue<pair<int, int>> Q;
//    queue<pair<int, int>> tmpQ;
//
//    for(int i=0;i<R;i++) {
//        for(int j=0;j<C;j++) {
//            cin >> ip;
//            if(ip == 'J') {
//                Q.push({i, j});
//            } else if(ip == '#') {
//                miro[i][j] = -1;
//            } else if(ip == 'F') {
//                miro[i][j] = -2;
//                tmpQ.push({i, j});
//            }
//        }
//    }
//
//    while(!tmpQ.empty()) {
//        Q.push(tmpQ.front());
//        tmpQ.pop();
//    }
//
//    bool isExit = false;
//
//    while(!Q.empty()) {
//        pair<int, int> cur = Q.front();Q.pop();
//        bool isFire = false;
//
//        if(miro[cur.X][cur.Y] == -2)
//            isFire = true;
//
//        for(int i=0;i<4;i++) {
//            int nx = cur.X + dx[i];
//            int ny = cur.Y + dy[i];
//
//            if(nx < 0 || ny < 0 || nx > R-1 || ny > C-1) {
//                if(!isFire) {
//                    isExit = true;
//                    cout << miro[cur.X][cur.Y] + 1;
//                    break;
//                }
//
//                continue;
//            }
//
//            if(isFire && (miro[nx][ny] == -2 || miro[nx][ny] == -1)) continue;
//            if(!isFire && miro[nx][ny] != 0) continue;
//
//            if(isFire) {
//                miro[nx][ny] = -2;
//                Q.push({nx, ny});
//            } else {
//                miro[nx][ny] = miro[cur.X][cur.Y] + 1;
//                Q.push({nx, ny});
//            }
//        }
//
////        for(int i=0;i<R;i++) {
////            for(int j=0;j<C;j++) {
////                cout << miro[i][j] << ' ';
////            }
////            cout << "\n";
////        }
////
////        cout << "-------------\n";
//
//
//        if(isExit)
//            break;
//
//    }
//
//    if(!isExit)
//        cout << "IMPOSSIBLE";
//
//    return 0;
//}

/* ��! <Ǯ�̳�Ʈ>

�����ڸ����� Ż�� :
"J"�����̸鼭 nx == -1 || ny == -1 || nx == R || ny == C �̸�
Ż�� => BFS ���� => Ż��ð� ���, isExit = true

ť.empty() �̸� BFS ����.

isExit = false��� IMPOSSIBLE ���.

*/

// BOJ 1697 ���ٲ���
//#include <iostream>
//#include <vector>
//#include <queue>
//#define END 100001
//
//using namespace std;
//
//int vis[100001];
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int S, D;
//
//    cin >> S >> D;
//
//    queue<pair<int, int>> Q;
//
//    Q.push({S, 0});
//
//    if(S==D) {
//        cout << 0;
//        Q.pop();
//    }
//
//    while(!Q.empty()) {
//        pair<int, int> cur = Q.front(); Q.pop();
//
//        int r = cur.first+1;
//        int l = cur.first-1;
//        int tp = cur.first*2;
//        int time = cur.second + 1;
//
//        if(r==D || l==D || tp==D) {
//            cout << time;
//            break;
//        }
//
//        if(r < END && !vis[r]) {
//            Q.push({r, time});
//            vis[r] = 1;
//        }
//
//        if(l >= 0 && !vis[l]) {
//            Q.push({l, time});
//            vis[l] = 1;
//        }
//
//        if(tp < END && !vis[tp]) {
//            Q.push({tp, time});
//            vis[tp] = 1;
//        }
//    }
//
//    return 0;
//
//}

/* ���ٲ��� <Ǯ�̳�Ʈ>

�׳� 1���� BFS �ϸ� ��. �� �ٵ� ť�θ����� �� �� �˾Ѵµ�
�����غ��� �湮 ó�� ������ ������ �迭 ��ߵǳ�
�װ� ���� �ؾ���.

�׸��� �ڳ� ���̽��� ���� ��ġ ���� ��� ���� ó������.

*/

// BOJ 7562 ����Ʈ�� �̵�
//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define X first
//#define Y second
//
//using namespace std;
//
//int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
//int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T;
//
//    cin >> T;
//
//    while(T--) {
//        int l;
//        int stX, stY;
//        int detX, detY;
//        int dis[300][300] = {0,};
//        bool isReached = false;
//
//        cin >> l;
//        cin >> stX >> stY;
//        cin >> detX >> detY;
//
//        queue<pair<int, int>> Q;
//
//        Q.push({stX, stY});
//        dis[stX][stY] = 1;
//
//        if(stX == detX && stY == detY) {
//            cout << "0\n";
//            continue;
//        }
//
//        while(!Q.empty()) {
//            pair<int, int> cur = Q.front(); Q.pop();
//            int nv = dis[cur.X][cur.Y] + 1;
//
//            //cout << "(" << cur.X << ", " << cur.Y << ")\n";
//
//            for(int i=0;i<8;i++) {
//                int nx = cur.X + dx[i];
//                int ny = cur.Y + dy[i];
//
//                if(nx < 0 || ny < 0 || nx > l-1 || ny > l-1) continue;
//                if(dis[nx][ny]) continue;
//
//                if(nx == detX && ny == detY) {
//                    isReached = true;
//                    cout << nv-1 << "\n";
//                    break;
//                }
//
//                Q.push({nx, ny});
//                dis[nx][ny] = nv;
//            }
//
//            if(isReached)
//                break;
//        }
//
//    }
//
//    return 0;
//}

// BOJ 1012 ����� ����
//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define X first
//#define Y second
//
//using namespace std;
//
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T;
//    int x, y;
//
//    cin >> T;
//
//    while(T--) {
//        int M, N, K;
//        int cnt = 0;
//        int farm[50][50] = {0,};
//        cin >> M >> N >> K;
//
//        queue<pair<int, int>> SP;
//
//        for(int i=0;i<K;i++) {
//            cin >> x >> y;
//            SP.push({x, y});
//            farm[x][y] = 1;
//        }
//
//        while(!SP.empty()) {
//            pair<int, int> sp = SP.front(); SP.pop();
//
//            if(farm[sp.X][sp.Y] == 1) {
//                queue<pair<int, int>> Q;
//                Q.push({sp.X, sp.Y});
//                cnt++;
//
//                while(!Q.empty()) {
//                    pair<int, int> cur = Q.front(); Q.pop();
//
//                    for(int i=0;i<4;i++) {
//                        int nx = cur.X+dx[i];
//                        int ny = cur.Y+dy[i];
//
//                        if(nx < 0 || ny < 0 || nx > M-1 || ny > N-1) continue;
//                        if(farm[nx][ny] != 1) continue;
//
//                        Q.push({nx, ny});
//                        farm[nx][ny] = 2;
//                    }
//                }
//            }
//        }
//
//        cout << cnt << "\n";
//    }
//
//    return 0;
//}

// BOJ 10026 ���ϻ���
//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define X first
//#define Y second
//
//using namespace std;
//
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//
//int vis1[100][100];
//int vis2[100][100];
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    char c;
//    int cnt1 = 0, cnt2 = 0;
//
//    cin >> N;
//
//    int **colors1 = new int*[N];
//    int **colors2 = new int*[N];
//    for(int i=0;i<N;i++) {
//        colors1[i] = new int[N];
//        colors2[i] = new int[N];
//    }
//
//    // R  = 2, G = 3(2), B = 1
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N;j++) {
//            cin >> c;
//            if(c=='R') {
//                colors1[i][j] = 2;
//                colors2[i][j] = 2;
//            } else if(c=='G') {
//                colors1[i][j] = 3;
//                colors2[i][j] = 2;
//            } else {
//                colors1[i][j] = 1;
//                colors2[i][j] = 1;
//            }
//        }
//    }
//
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N;j++) {
//            if(!vis1[i][j]) {
//                cnt1++;
//                queue<pair<int, int>> Q;
//
//                Q.push({i, j});
//
//                while(!Q.empty()) {
//                    pair<int, int> cur = Q.front(); Q.pop();
//
//                    for(int k=0;k<4;k++) {
//                        int nx = cur.X+dx[k];
//                        int ny = cur.Y+dy[k];
//
//                        if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1) continue;
//                        if(vis1[nx][ny]) continue;
//                        if(colors1[cur.X][cur.Y] != colors1[nx][ny]) continue;
//
//                        Q.push({nx, ny});
//                        vis1[nx][ny] = 1;
//                    }
//                }
//            }
//
//            if(!vis2[i][j]) {
//                cnt2++;
//                queue<pair<int, int>> Q;
//
//                Q.push({i, j});
//
//                while(!Q.empty()) {
//                    pair<int, int> cur = Q.front(); Q.pop();
//
//                    for(int k=0;k<4;k++) {
//                        int nx = cur.X+dx[k];
//                        int ny = cur.Y+dy[k];
//
//                        if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1) continue;
//                        if(vis2[nx][ny]) continue;
//                        if(colors2[cur.X][cur.Y] != colors2[nx][ny]) continue;
//
//                        Q.push({nx, ny});
//                        vis2[nx][ny] = 1;
//                    }
//                }
//            }
//        }
//    }
//
//    cout << cnt1 << ' ' << cnt2;
//
//    for(int i=0;i<N;i++) {
//        delete[] colors1[i];
//        delete[] colors2[i];
//    }
//    delete[] colors1;
//    delete[] colors2;
//
//    return 0;
//}

// BOJ 7569 �丶��
//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define X first
//#define Y second
//
//using namespace std;
//
//int dx[6] = {-1, 0, 1, 0, 0, 0};
//int dy[6] = {0, -1, 0, 1, 0, 0};
//int dz[6] = {0, 0, 0, 0, -1, 1};
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int M, N, H; // [H][N][M]
//    int zeros = 0;
//    bool isEnd = false;
//
//    cin >> M >> N >> H;
//
//    queue<pair<pair<int, int>, int>> Q;
//    vector<vector<vector<int>>> farm(H, vector<vector<int>>(N, vector<int>(M)));
//    vector<vector<vector<int>>> vis(H, vector<vector<int>>(N, vector<int>(M, 0)));
//
//    for(int i=0;i<H;i++) {
//        for(int j=0;j<N;j++) {
//            for(int k=0;k<M;k++) {
//                cin >> farm[i][j][k];
//
//                if(farm[i][j][k] > 0) {
//                    Q.push({{j, k}, i});
//                    vis[i][j][k] = 0;
//                    farm[i][j][k] = 1;
//                }
//                else if(farm[i][j][k] == 0)
//                    zeros++;
//            }
//        }
//    }
//
//    if(zeros == 0)
//        cout << 0;
//    else {
//        while(!Q.empty()) {
//            pair<pair<int, int>, int> cur = Q.front(); Q.pop();
//            int nv = vis[cur.Y][cur.X.X][cur.X.Y] + 1;
//
//            for(int i=0;i<6;i++) {
//                int nx = cur.X.X + dx[i];
//                int ny = cur.X.Y + dy[i];
//                int nz = cur.Y + dz[i];
//
//                if(nx < 0 || ny < 0 || nz < 0 || nx > N-1 || ny > M-1 || nz > H-1) continue;
//                if(farm[nz][nx][ny] != 0) continue;
//
//                zeros--;
//                if(zeros == 0)
//                {
//                    cout << nv;
//                    isEnd = true;
//                    break;
//                }
//
//                farm[nz][nx][ny] = 1;
//                vis[nz][nx][ny] = nv;
//                Q.push({{nx, ny}, nz});
//
//            }
//
////            for(int i=0;i<H;i++) {
////                for(int j=0;j<N;j++) {
////                    for(int k=0;k<M;k++)
////                        cout << farm[i][j][k];
////                    cout << "\n";
////                }
////            }
//
////            cout << "---------------\n\n";
//
//            if(isEnd)
//                break;
//        }
//
//        if(zeros > 0)
//            cout << -1;
//    }
//
//    return 0;
//}

/* �丶��2 <Ǯ�̳�Ʈ>

��, 3���� �迭 �߸����� ���� �ð� ����....

*/

// BOJ 5427 ��
//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define X first
//#define Y second
//
//using namespace std;
//
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T;
//
//    cin >> T;
//
//    while(T--) {
//
//        int R, C;
//        char ip;
//
//        cin >> C >> R;
//
//        int **miro = (int**)malloc(sizeof(int*)*R);
//        for(int i=0;i<R;i++)
//            miro[i] = (int*)calloc(C, sizeof(int));
//
//       // 0 = can go, -1 = wall, -2 = fire
//
//        queue<pair<int, int>> Q;
//        queue<pair<int, int>> tmpQ;
//
//        for(int i=0;i<R;i++) {
//            for(int j=0;j<C;j++) {
//                cin >> ip;
//                if(ip == '@') {
//                    Q.push({i, j});
//                } else if(ip == '#') {
//                    miro[i][j] = -1;
//                } else if(ip == '*') {
//                    miro[i][j] = -2;
//                    tmpQ.push({i, j});
//                }
//            }
//        }
//
//        while(!tmpQ.empty()) {
//            Q.push(tmpQ.front());
//            tmpQ.pop();
//        }
//
//        bool isExit = false;
//
//        while(!Q.empty()) {
//            pair<int, int> cur = Q.front();Q.pop();
//            bool isFire = false;
//
//            if(miro[cur.X][cur.Y] == -2)
//                isFire = true;
//
//            for(int i=0;i<4;i++) {
//                int nx = cur.X + dx[i];
//                int ny = cur.Y + dy[i];
//
//                if(nx < 0 || ny < 0 || nx > R-1 || ny > C-1) {
//                    if(!isFire) {
//                        isExit = true;
//                        cout << miro[cur.X][cur.Y] + 1 << "\n";
//                        break;
//                    }
//
//                    continue;
//                }
//
//                if(isFire && (miro[nx][ny] == -2 || miro[nx][ny] == -1)) continue;
//                if(!isFire && miro[nx][ny] != 0) continue;
//
//                if(isFire) {
//                    miro[nx][ny] = -2;
//                    Q.push({nx, ny});
//                } else {
//                    miro[nx][ny] = miro[cur.X][cur.Y] + 1;
//                    Q.push({nx, ny});
//                }
//            }
//
//    //        for(int i=0;i<R;i++) {
//    //            for(int j=0;j<C;j++) {
//    //                cout << miro[i][j] << ' ';
//    //            }
//    //            cout << "\n";
//    //        }
//    //
//    //        cout << "-------------\n";
//
//
//            if(isExit)
//                break;
//
//        }
//
//        if(!isExit)
//            cout << "IMPOSSIBLE\n";
//
//        for(int i=0;i<R;i++)
//            free(miro[i]);
//        free(miro);
//    }
//
//    return 0;
//}

// BOJ 2206 �� �μ��� �̵��ϱ�
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int N, M, X;
//char arr[1001][1001];
//int dists[1001][1001][2];
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//
//void bfs() {
//	queue<pair<pair<int, int>, bool>> q; // x, y, ��������
//	q.push({ {0,0}, 0 });
//	dists[0][0][0] = dists[0][0][1] = 1;
//
//	while (!q.empty()) {
//		int cx = q.front().first.first;
//		int cy = q.front().first.second;
//		bool breakWall = q.front().second;
//		q.pop();
//
//		if (cx == M - 1 && cy == N - 1)	{
//            cout << dists[cy][cx][breakWall];
//            return;
//        }
//
//		for (int i = 0;i < 4;i++) {
//			int nx = cx + dx[i], ny = cy + dy[i];
//			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
//
//			int n_dist = dists[cy][cx][breakWall] + 1;
//
//			// �� �μ��� �̵�
//			if (arr[ny][nx] == '1' && !breakWall) {
//				q.push({ {nx,ny},1 });
//				dists[ny][nx][1] = n_dist;
//			}
//
//			// ĭ ������
//			if (arr[ny][nx] == '0' && dists[ny][nx][breakWall]==0) {
//				q.push({ {nx,ny},breakWall });
//				dists[ny][nx][breakWall] = n_dist;
//			}
//		}
//	}
//
//	// ���� ����
//	cout << -1;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> N >> M;
//
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < M;j++)
//			cin >> arr[i][j];
//
//	bfs();
//}


// BOJ 9466 �� ������Ʈ
//#include <iostream>
//#include <list>
//#include <queue>
//
//using namespace std;
//
//void bfs(int *vis, int *ch, bool *check, int n) {
//    int noTeam = n;
//
//    for(int i=0;i<n;i++) {
//        if(check[i]) continue;
//
//        int pv=ch[i]; vis[i]++;
//        list<int> idx;
//        idx.push_back(i);
//        while(true) {
//            if(check[pv]) break;
//            vis[pv]++;
//            idx.push_back(pv);
//            if(vis[pv] > 2) break;
//            if(vis[pv] > 1) noTeam--;
//            pv = ch[pv];
//        }
//
//        for(auto it : idx)
//            if(!check[it]) check[it]=true;
//    }
//
////    cout << "vis: ";
////    for(int i=0;i<n;i++) {
////        cout << vis[i] << " ";
////    }
////    cout << "\n";
//
//    cout << noTeam << "\n";
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T;
//    int n;
//
//    cin >> T;
//
//    while(T--) {
//        int vis[100000] = {0,};
//        bool checking[100000] = {false,};
//        int choose[100000];
//        cin >> n;
//
//        for(int i=0;i<n;i++) {
//            cin >> choose[i];
//            choose[i]--;
//        }
//
//        bfs(vis, choose, checking, n);
//    }
//
//    return 0;
//}

/* �� ������Ʈ <Ǯ�̳�Ʈ>

vis[i] > 0�̸� ������δ� X
������ڸ��� vis > 0�� ���� �湮�ϸ� �� �ٷ� break;

���鼭 vis[i] > 2�� �Ǹ� �ݺ�����Ŭ�����̹Ƿ� break;
���鼭 vis[i] > 1�Ǹ� �³׵��� �� ���ϴ� ������ noTeam--;

���� ó���� Ǯ������ 24%Ʋ. �����غ��� ������ڸ��� vis > 0�� �� ���ŷδ� ���������.
�׷��� list���� �� ����Ŭ �˻��ϸ鼭 �³׵� ���.
�� ����Ŭ �˻� ������ �� �˻��ߴ� �ֵ��� ������ check�� ��� �ٽô� �ȿ�����.

�Ѹ���� check�� ��¥ visited(�湮Ȯ��)�̰�,
vis�� �� ����Ŭ �˻�(���� ���ϴ��� Ȯ��)

����Ŭ �˻� ���̵���

1 2 3 4 5
3 1 4 5 3

1 3 4 5 3 4 5 ���ø� �����غ��ٰ� ���ö���.

�ٵ� ���߿� �����غ���, ������ Ȱ���ؼ��� ������ �� �ϴ�.
stack�� ��ư��鼭 vis�� '��'�� �� ������ pop�ذ��鼭 '��' vis�� �� ���� ������ noTeam--;
=�̷��� vis�� �ᵵ OK
*/

// BOJ 2573 ����
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//int height[300][300];
//
//
//void bfs(queue<pair<int, int>> &gen, int n, int m) {
//    int years = 0;
//
//    while(!gen.empty()) {
//        int gen_len = gen.size();
//        queue<pair<int, int>> q;
//        bool vis[300][300] = {0,};
//        int cnt = 0;
//
//        for(int g=0;g<gen_len;g++) {
//            if(!vis[gen.front().first][gen.front().second]) {
//                cnt++;
//                q.push(gen.front());
//                vis[q.front().first][q.front().second] = true;
//                while(!q.empty()) {
//                    pair<int, int> cur = q.front(); q.pop();
//                    int x = cur.first;
//                    int y = cur.second;
//
//                    for(int i=0;i<4;i++) {
//                        int nx = x+dx[i];
//                        int ny = y+dy[i];
//
//                        if(nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
//                        if(height[nx][ny] <= 0) {
//                            if(!vis[nx][ny] && height[x][y] > 0)
//                                height[x][y]--;
//                            continue;
//                        }
//                        if(vis[nx][ny]) continue;
//
//                        vis[nx][ny] = true;
//                        q.push({nx, ny});
//                    }
//
//                    if(height[x][y] > 0)
//                        gen.push({x, y});
//                }
//            }
//            gen.pop();
//        }
//
////        cout << "\n";
////        for(int i=0;i<n;i++) {
////            for(int j=0;j<m;j++) {
////                cout << height[i][j] << ' ';
////            }
////            cout << "\n";
////        }
//
//        if(cnt >= 2) {
//            cout << years;
//            return;
//        }
//
//        years++;
//    }
//
//    cout << 0;
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N, M;
//
//    cin >> N >> M;
//
//    queue<pair<int, int>> gen;
//
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<M;j++) {
//            cin >> height[i][j];
//            if(height[i][j] > 0)
//                gen.push({i, j});
//        }
//    }
//
//    bfs(gen, N, M);
//
//    return 0;
//}

/* ���� <Ǯ�̳�Ʈ>

N <= 300, M <= 300
�ϴ� ��÷�� ���� �ִ� �ֵ� push.

ť�� 2��, bfs(q) - ���� ���� ��Ͽ�(gen)

�ϴ� bfs

bfs�ϸ鼭 ������ �������� ť�� �� �� �ִ��� �۾��ϱ�.
gen���� pop�ؼ� bfs, ���� vis���� ����
	cnt++;
	- bfs : ���� ���� �մ���(vis�� 0 �˻�)
	- gen : ������ �����ؿ� �� �� �ִ��� �˻��ϰ� gen.push()

cnt�� 2 �̻��̸� ��(years���).
���� gen�� empty�� 0.

*/

// BOJ 2146 �ٸ� �����
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <cstdlib>
//
//#define X first
//#define Y second
//#define MAX 2147483647
//
//using namespace std;
//
//int ocean[100][100];
//bool vis[100][100];
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    queue<pair<int, int>> B;
//    list<list<pair<int, int>>> lands;
//
//    cin >> N;
//
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N;j++) {
//            cin >> ocean[i][j];
//            if(ocean[i][j] == 1)
//                B.push({i, j});
//        }
//    }
//
//    while(!B.empty()) {
//        list<pair<int, int>> land;
//        queue<pair<int, int>> Q;
//        Q.push(B.front()); B.pop();
//
//        if(!vis[Q.front().X][Q.front().Y]) {
//            vis[Q.front().X][Q.front().Y] = true;
//            bool isBay = false;
//
//            while(!Q.empty()) {
//                pair<int, int> cur = Q.front(); Q.pop();
//                int cx = cur.X;
//                int cy = cur.Y;
//
//                for(int i=0;i<4;i++) {
//                    int nx = cx + dx[i];
//                    int ny = cy + dy[i];
//
//                    if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1) continue;
//                    if(vis[nx][ny]) continue;
//                    if(ocean[nx][ny] == 0) {
//                        isBay = true;
//                        continue;
//                    }
//
//                    Q.push({nx, ny});
//                    vis[nx][ny] = true;
//                }
//
//                if(isBay) land.push_back({cx, cy});
//            }
//
//            lands.push_back(land);
//        }
//
//    }
//
//    auto plf = lands.begin();
//    auto pl = lands.begin();
//    int minGap = MAX;
//    int xGap, yGap, gapSum;
//
//    while(!lands.empty()) {
//        plf = lands.begin();
//        pl = lands.begin();
//
//        while(true) {
//            pl++;
//
//            if(pl == lands.end())
//                break;
//
//            for(auto i : *plf) {
//                for(auto j : *pl) {
//                    xGap = abs(i.X - j.X);
//                    yGap = abs(i.Y - j.Y);
//                    gapSum = xGap + yGap - 1;
//
//                    if(gapSum > 0 && minGap > gapSum)
//                        minGap = gapSum;
//                }
//            }
//        }
//
//        lands.erase(lands.begin());
//    }
//
//    cout << minGap;
//
//    return 0;
//}

/* �ٸ� ����� <Ǯ�̳�Ʈ>

(5, 4)
(8, 5)

3 + 1 - 1 = 3

(4, 5)
(3, 9)

1 + 4 - 1 = 4

÷���� ��� �ؾ� ���� ������ �ִܰŸ��� ���ұ�. �����ߴµ� �� ������
�ٸ� ������ BFS�� �ʹ� ���� ������(�ð����⵵ ũ�ٴ� ��) ���Ұ� ���Ƽ�
�� ��ǥ���� ���ٴ� ������ �ϰ� �Ǿ���. �� ����ó��.

1. �ϴ� ������ ���еǰ� ��ǥ ������ �Ѵ�
- �� �ϳ��� �� list, list�� ���� ��ǥ�� ��-��-��-�� �߿� �ϳ��� �ٴٰ� �־��(������ ���ܽ�Ű�� ����)

2. �ٸ��� ��ǥ���� ���� �ּڰ��� ������ �Ѵ�.
- 2�� ���� ����Ʈ, �� ���� n���� nC2���� ��-������ �ϴ� ��

*/

// BOJ 13549 ���ٲ��� 3
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//bool vis[100001];
//int sec[100001];
//int dx[2] = {-1, 1};
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N, K;
//
//    cin >> N >> K;
//
//    queue<int> Q;
//    Q.push(N);
//    vis[N] = true;
//
//    while(!Q.empty()) {
//        int cur = Q.front(); Q.pop();
//        int nx;
//
//        if(cur == K) {
//            cout << sec[cur];
//            break;
//        }
//
//        if(cur < K && cur*2 <= 100000) {
//            nx = cur*2;
//
//            if(vis[nx]) {
//                if(sec[nx] > sec[cur]) sec[nx] = sec[cur];
//            } else {
//                vis[nx] = true;
//                sec[nx] = sec[cur];
//                Q.push(nx);
//            }
//        }
//
//        nx = cur + 1;
//        if(cur < K && nx <= 100000) {
//            if(vis[nx]) {
//                if(sec[nx] > sec[cur]+1) sec[nx] = sec[cur]+1;
//            } else {
//                vis[nx] = true;
//                sec[nx] = sec[cur]+1;
//                Q.push(nx);
//            }
//        }
//
//        nx = cur - 1;
//        if(nx >= 0) {
//            if(vis[nx]) {
//                if(sec[nx] > sec[cur]+1) sec[nx] = sec[cur]+1;
//            } else {
//                vis[nx] = true;
//                sec[nx] = sec[cur]+1;
//                Q.push(nx);
//            }
//        }
//
//    }
//
//    return 0;
//}

/* ���ٲ��� 3 <Ǯ�̳�Ʈ>

1. ���� ��ġ���� �̹� Ŭ ��� *2�� +1�� ���� �ʴ´�.
2. �̹� vis�ߴ��� Ȯ���ϰ�, �̹� �湮�ߴ� �ϴ��� ���� sec���� ������ sec ���� ���Ͽ�, �� �۴ٸ� ����(�����ɷ�).
3. *2�� ��쿡�� sec�� +1�� ���� �ʴ´�.

*/

// BOJ 1600 ���� �ǰ��� ������
//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define X first
//#define Y second
//
//using namespace std;
//
//int world[200][200];
//int dis[200][200];
//int kCnt[200][200];
//
//int dx[12] = {-1, 0, 1, 0, -2, -2, -1, -1, 1, 1, 2, 2};
//int dy[12] = {0, -1, 0, 1, -1, 1, -2, 2, -2, 2, -1, 1};
//
//void bfs(int w, int h, int k) {
//    queue<pair<pair<int, int>, int>> Q;
//    Q.push({{0, 0}, 0});
//    dis[0][0] = 1; // �湮ǥ�ø� ���� 1�� ����, �������� 1 ������.
//
//    while(!Q.empty()) {
//        pair<pair<int, int>, int> cur = Q.front(); Q.pop();
//        int cx = cur.X.X;
//        int cy = cur.X.Y;
//        int ck = cur.Y;
//        int nd = dis[cx][cy]+1;
//
//        // reach to the end
//        if(cx == h-1 && cy == w-1) {
//            cout << dis[cx][cy] - 1;
//            return;
//        }
//
//        // basic locomotion
//        for(int i=0;i<4;i++) {
//            int nx = cx+dx[i];
//            int ny = cy+dy[i];
//
//            if(nx < 0 || ny < 0 || nx > h-1 || cy > w-1) continue;
//            if(world[nx][ny]) continue;
//            if(dis[nx][ny]) {
//                if(dis[nx][ny] <= nd && kCnt[nx][ny] <= ck) continue;
//            }
//
//            Q.push({{nx,ny},ck});
//            dis[nx][ny] = nd;
//            kCnt[nx][ny] = ck;
//        }
//
//        // can be horse
//        if(ck < k) {
//            for(int i=4;i<12;i++) {
//                int nx = cx+dx[i];
//                int ny = cy+dy[i];
//
//                if(nx < 0 || ny < 0 || nx > h-1 || cy > w-1) continue;
//                if(world[nx][ny]) continue;
//                if(dis[nx][ny]) {
//                    if(dis[nx][ny] <= nd && kCnt[nx][ny] <= ck+1) continue;
//                }
//
//                Q.push({{nx,ny},ck+1});
//                dis[nx][ny] = nd;
//                kCnt[nx][ny] = ck+1;
//            }
//        }
//
//    }
//
//    cout << "-1";
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int W, H, K;
//
//    cin >> K;
//    cin >> W >> H;
//
//    for(int i=0;i<H;i++) {
//        for(int j=0;j<W;j++) {
//            cin >> world[i][j];
//        }
//    }
//
//    bfs(W, H, K);
//
//    return 0;
//}

/* ���� �ǰ��� ������ <Ǯ�̳�Ʈ>

����ġ : H-1, W-1 �̸� �� ��ġ ���� ���ۼ� �� ��� �� ����.

1. �̹� K�� �پ����� �˻�
-> K�� �پ����� ������ �ȴ�

if(�������̻���ϴ»��� �ƴϸ�)
������ ����
1. �� �ٱ����� �˻�
2. ��ֹ� ������ �˻�
3. �̹� �湮�ߴ��� �˻�,
=>�̹� �湮�߾ ���� ���ۼ� �� ������ push.


�� �����µ��� ������������ -1 ���.

�ߴµ� Ʋ�Ƚ��ϴ�. �����غ��� ������ ���� �ݷʰ� �־���.


1
6 5
0 1 1 1 1 1
0 1 1 1 1 1
0 0 0 1 1 1
1 1 1 1 0 0
1 1 0 0 0 0

ans: 7

�׷��� '�̹� �湮�߾ ���� ���ۼ� �� ������ push'�� �� �����ϰ� ��.
���� �� Ƚ���� �����Ͽ� ��� = kCnt
'�̹� �湮�߾ ���� ���ۼ� �� �۰�, ���� �� Ƚ�� �� ������ push.'

*/
