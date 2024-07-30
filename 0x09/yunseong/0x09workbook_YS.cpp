// BOJ 1926 그림
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

/* 그림 <풀이과정>

1의 좌표들 기록,
하나 씩 방문하는데
visited 상태면 그냥 넘어가고
아니라면 pic_cnt++하고 BFS.
BFS 마치면 길이 max와 비교.

*/

// BOJ 2178 미로
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

/* 아 생각해보니 그냥 미로에다가 값 쓰면 되는구나. 괜히
큐 저렇게 썼네... */

// BOJ 7576 토마토
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


/* 바킹독씨는 dist라는 거리 배열을 따로 두고
각 시작점을 0, 거기서부터 각자 +1씩 하게 하여 날짜를 기록하고
마지막에 전체 순회에서 다 익지 못했는가 와 최종 날짜를 검사했다. */

// BOJ 4179 불!
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

/* 불! <풀이노트>

가장자리에서 탈출 :
"J"상태이면서 nx == -1 || ny == -1 || nx == R || ny == C 이면
탈출 => BFS 종료 => 탈출시간 출력, isExit = true

큐.empty() 이면 BFS 종료.

isExit = false라면 IMPOSSIBLE 출력.

*/

// BOJ 1697 숨바꼭질
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

/* 숨바꼭질 <풀이노트>

그냥 1차원 BFS 하면 끝. 아 근데 큐로만으로 될 줄 알앗는데
생각해보니 방문 처리 때문에 어차피 배열 써야되네
그걸 순간 잊었다.

그리고 코너 케이스로 둘이 위치 같을 경우 따로 처리해줌.

*/

// BOJ 7562 나이트의 이동
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

// BOJ 1012 유기농 배추
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

// BOJ 10026 적록색약
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

// BOJ 7569 토마토
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

/* 토마토2 <풀이노트>

아, 3차원 배열 잘못만들어서 괜히 시간 날림....

*/

// BOJ 5427 불
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

// BOJ 2206 벽 부수고 이동하기
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
//	queue<pair<pair<int, int>, bool>> q; // x, y, 벽뚫유무
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
//			// 벽 부수고 이동
//			if (arr[ny][nx] == '1' && !breakWall) {
//				q.push({ {nx,ny},1 });
//				dists[ny][nx][1] = n_dist;
//			}
//
//			// 칸 지나기
//			if (arr[ny][nx] == '0' && dists[ny][nx][breakWall]==0) {
//				q.push({ {nx,ny},breakWall });
//				dists[ny][nx][breakWall] = n_dist;
//			}
//		}
//	}
//
//	// 도착 못함
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


// BOJ 9466 텀 프로젝트
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

/* 텀 프로젝트 <풀이노트>

vis[i] > 0이면 출발지로는 X
출발하자마자 vis > 0인 곳을 방문하면 걍 바로 break;

돌면서 vis[i] > 2가 되면 반복사이클링중이므로 break;
돌면서 vis[i] > 1되면 걔네들은 팀 속하는 것으로 noTeam--;

으로 처음에 풀었더니 24%틀. 생각해보니 출발하자마자 vis > 0인 곳 저거로는 불충분했음.
그래서 list만들어서 한 사이클 검사하면서 걔네들 담기.
한 사이클 검사 끝나면 그 검사했던 애들을 꺼내어 check에 담아 다시는 안오도록.

한마디로 check가 진짜 visited(방문확인)이고,
vis는 한 사이클 검사(팀에 속하는지 확인)

사이클 검사 아이디어는

1 2 3 4 5
3 1 4 5 3

1 3 4 5 3 4 5 예시를 생각해보다가 떠올랐음.

근데 나중에 생각해보니, 스택을 활용해서도 가능할 듯 하다.
stack에 담아가면서 vis한 '곳'을 또 만나면 pop해가면서 '그' vis한 곳 만날 때까지 noTeam--;
=이러면 vis만 써도 OK
*/

// BOJ 2573 빙산
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

/* 빙산 <풀이노트>

N <= 300, M <= 300
일단 맨첨에 높이 있는 애들 push.

큐는 2개, bfs(q) - 매해 빙산 기록용(gen)

일단 bfs

bfs하면서 본인이 다음해의 큐에 들어갈 수 있는지 작업하기.
gen에서 pop해서 bfs, 만약 vis면은 안함
	cnt++;
	- bfs : 옆에 빙산 잇는지(vis와 0 검사)
	- gen : 본인이 다음해에 들어갈 수 있는지 검사하고 gen.push()

cnt가 2 이상이면 끝(years출력).
만약 gen이 empty면 0.

*/

// BOJ 2146 다리 만들기
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

/* 다리 만들기 <풀이노트>

(5, 4)
(8, 5)

3 + 1 - 1 = 3

(4, 5)
(3, 9)

1 + 4 - 1 = 4

첨에는 어떻게 해야 섬과 섬간의 최단거리를 구할까. 생각했는데 각 섬에서
다른 섬으로 BFS는 너무 많은 연산을(시간복잡도 크다는 뜻) 요할것 같아서
걍 좌표끼리 뺀다는 생각을 하게 되었음. 위 예시처럼.

1. 일단 섬들을 구분되게 좌표 저장을 한다
- 섬 하나당 한 list, list에 들어가는 좌표는 상-하-좌-우 중에 하나라도 바다가 있어야(내륙은 제외시키기 위함)

2. 다른섬 좌표끼리 빼서 최솟값을 답으로 한다.
- 2중 포문 리스트, 섬 개수 n개면 nC2번의 섬-연산을 하는 격

*/

// BOJ 13549 숨바꼭질 3
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

/* 숨바꼭질 3 <풀이노트>

1. 동생 위치보다 이미 클 경우 *2와 +1은 하지 않는다.
2. 이미 vis했는지 확인하고, 이미 방문했다 하더라도 전에 sec값과 갱신할 sec 값을 비교하여, 더 작다면 갱신(작은걸로).
3. *2할 경우에는 sec에 +1을 하지 않는다.

*/

// BOJ 1600 말이 되고픈 원숭이
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
//    dis[0][0] = 1; // 방문표시를 위해 1로 시작, 마지막에 1 빼주자.
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

/* 말이 되고픈 원숭이 <풀이노트>

현위치 : H-1, W-1 이면 현 위치 누적 동작수 값 출력 후 종료.

1. 이미 K번 뛰었는지 검사
-> K번 뛰었으면 점프는 안댐

if(점프더이상못하는상태 아니면)
점프도 가능
1. 맵 바깥인지 검사
2. 장애물 위인지 검사
3. 이미 방문했는지 검사,
=>이미 방문했어도 누적 동작수 더 작으면 push.


다 끝났는데도 도착못했으면 -1 출력.

했는데 틀렸습니다. 생각해보니 다음과 같은 반례가 있었음.


1
6 5
0 1 1 1 1 1
0 1 1 1 1 1
0 0 0 1 1 1
1 1 1 1 0 0
1 1 0 0 0 0

ans: 7

그래서 '이미 방문했어도 누적 동작수 더 작으면 push'를 더 느슨하게 함.
말이 된 횟수도 누적하여 기록 = kCnt
'이미 방문했어도 누적 동작수 더 작고, 말이 된 횟수 더 적으면 push.'

*/
