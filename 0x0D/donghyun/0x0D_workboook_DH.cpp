#include <bits/stdc++.h>
using namespace std;

/* 연습문제 - 1 : 감시 
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 
int n, m;
int board1[10][10]; 
int board2[10][10]; 
vector<pair<int, int> > cctv; 

bool OOB(int a, int b) { 
    return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int dir) {
    dir %= 4;
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board2[x][y] == 6) return; 
        if (board2[x][y] != 0) continue; 
        board2[x][y] = 7; 
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int mn = 0; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            cin >> board1[i][j];

            if (board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({ i,j });
            if (board1[i][j] == 0) mn++;
        }
    }

    for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) { 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) board2[i][j] = board1[i][j];
        }

        int brute = tmp;

        for (int i = 0; i < cctv.size(); i++) {

            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;

            if (board1[x][y] == 1) {
                upd(x, y, dir);
            }
            else if (board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            }
            else if (board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            }
            else if (board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            }
            else { 
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }

        int val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) val += (board2[i][j] == 0);
        }
        mn = min(mn, val);
    }
    cout << mn;
}
*/

/* 연습문제 - 12 : 스티커 붙이기 
int m, n, k, r, c, ans;
int board[41][41];
int stick[11][11];


void rot() {

    int temp[12][12];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) temp[i][j] = stick[i][j];
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) stick[i][j] = temp[r - j - 1][i];
    }

    swap(c, r);
}

bool check(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[x + i][y + j] == 1 && stick[i][j] == 1) return false;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (stick[i][j] == 1) board[x + i][y + j] = 1;
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < 41; i++) fill(board[i], board[i] + 41, 0);
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cin >> stick[i][j];
        }

        for (int i = 0; i < 4; i++) {
            bool flag = false;
            for (int x = 0; x <= n - r; x++) {
                if (flag) break;
                for (int y = 0; y <= m - c; y++) {
                    if (check(x, y)) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
            rot();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ans += board[i][j];
    }
    cout << ans;
}
*/

/* 연습문제3 - 2048(easy) 
int board1[21][21];
int board2[21][21];
int n;

void rot() { 
    int tmp[21][21];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) tmp[i][j] = board2[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) board2[i][j] = tmp[n - 1 - j][i];
    }
}

void tilt(int dir) {
    while (dir--) rot();
    for (int i = 0; i < n; i++) {
        int tilted[21] = {};
        int idx = 0;
        for (int j = 0; j < n; j++) {

            if (board2[i][j] == 0) continue;
            if (tilted[idx] == 0) tilted[idx] = board2[i][j];
            else if (tilted[idx] == board2[i][j]) tilted[idx++] *= 2;
            else tilted[++idx] = board2[i][j];

        }
        for (int j = 0; j < n; j++) board2[i][j] = tilted[j];
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board1[i][j];
    }

    int mx = 0;
    for (int tmp = 0; tmp < 1024; tmp++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) board2[i][j] = board1[i][j];
        }
        int brute = tmp;

        for (int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) mx = max(mx, board2[i][j]);
        }
    }
    cout << mx;
}
*/

/* 연습문제4 - 치킨배달
#define X first
#define Y second

int board[55][55];
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) house.push_back({ i, j });
            if (board[i][j] == 2) chicken.push_back({ i, j });
        }
    }
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
    int mn = 0x7f7f7f7f;
    do {
        int dist = 0;
        for (auto h : house) {
            int tmp = 0x7f7f7f7f;
            for (int i = 0; i < chicken.size(); i++) {
                if (brute[i] == 0) continue;
                tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y)); // 집의 치킨 거리 갱신
            }
            dist += tmp;
        }
        mn = min(mn, dist);
    } while (next_permutation(brute.begin(), brute.end()));
    cout << mn;
}

*/

/* 문제 - 11559 : 뿌요뿌요
bool isPuyo; 
bool vis[12][6]; 
string board[12]; 
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ans;

void resetVis() {
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 6; ++j)
            vis[i][j] = false;
}

void puyo(int x, int y) {
    bool doErase = false; 
    vis[x][y] = true;
    char color = board[x][y];
    queue<pair<int, int> > q;
    vector<pair<int, int>> tmp;
    q.push({ x, y }); 
    tmp.push_back({ x, y });
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
            vis[nx][ny] = true;
            q.push({ nx, ny }); 
            tmp.push_back({ nx, ny });
        }
    }

    if (tmp.size() >= 4) {
        isPuyo = true;
        for (auto cur : tmp)
            board[cur.first][cur.second] = '.';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 12; ++i)
        cin >> board[i];
    do {
        isPuyo = false;
        for (int i = 0; i < 6; ++i) {
            for (int j = 10; j >= 0; --j) {
                int tmp = j;
                while (tmp < 11 && board[tmp + 1][i] == '.') {
                    swap(board[tmp][i], board[tmp + 1][i]);
                    ++tmp;
                }
            }
        }
        for (int i = 0; i < 12; ++i)
            for (int j = 0; j < 6; ++j)
                if (!vis[i][j] && board[i][j] != '.')
                    puyo(i, j);

        if (isPuyo) ++ans; 
        resetVis();
    } while (isPuyo); 
    cout << ans;
}

*/



/* 문제 - 14891 : 톱니바퀴
int n,ans = 0;
char tool[4][9];
char tool2[4][2];
bool vis[4];

void func(int a, int b) {
    vis[a] = true;
    if (b == 1) {
        for (int i = 8; i > 0; i--) {
            tool[a][i] = tool[a][i-1];
        }
        tool[a][0] = tool[a][8];
    }
    else {
        tool[a][8] = tool[a][0];
        for (int i = 0; i < 8; i++) {
            tool[a][i] = tool[a][i+1];
        }
    }
    if (a - 1 > -1 && tool2[a][1] != tool2[a - 1][0] && !vis[a-1]) func(a - 1, b * -1);
    if (a + 1 < 4 && tool2[a][0] != tool2[a + 1][1] && !vis[a+1]) func(a + 1, b * -1);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> tool[i][j];
        }
    }
    cin >> n;
    while (n--) {
        fill(vis, vis + 4, false);
        for (int i = 0; i < 4; i++) {
            tool2[i][0] = tool[i][2];
            tool2[i][1] = tool[i][6];
        }
        int a, b;
        cin >> a >> b;
        func(a-1, b);
    }
    if (tool[0][0] == '1') ans += 1;
    if (tool[1][0] == '1') ans += 2;
    if (tool[2][0] == '1') ans += 4;
    if (tool[3][0] == '1') ans += 8;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cout << tool[i][j];
        }
        cout << "\n";
    }
    cout << ans;
}
*/

/* 문제 : 14499 - 주사위 굴리기 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

*/

/* 문제 : 13355 - 트럭 */
int n, w, L;
int truck[1001];
int dari[1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) cin >> truck[i];

    
}


/* 문제 : 16895 - Maaaaaaaaaze 
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
*/
