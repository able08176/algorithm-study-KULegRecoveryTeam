// BOJ 15683 감시
//#include <iostream>
//
//using namespace std;
//
//int office[8][8];
//int pc;
//int cctv[8][2];
//int n, m;
//int min_cnt = 64;
//
//void marking(int x, int y, int direct) {
//    if(direct == 0) { // up
//        for(int i=x-1;i>=0;i--) {
//            if(office[i][y] == 6)
//                break;
//            else if(office[i][y] <= 0)
//                office[i][y]--;
//        }
//    }
//    else if(direct == 1) { // right
//        for(int i=y+1;i<m;i++) {
//            if(office[x][i] == 6)
//                break;
//            else if(office[x][i] <= 0)
//                office[x][i]--;
//        }
//    }
//    else if(direct == 2) { // down
//        for(int i=x+1;i<n;i++) {
//            if(office[i][y] == 6)
//                break;
//            else if(office[i][y] <= 0)
//                office[i][y]--;
//        }
//    }
//    else { // left
//        for(int i=y-1;i>=0;i--) {
//            if(office[x][i] == 6)
//                break;
//            else if(office[x][i] <= 0)
//                office[x][i]--;
//        }
//    }
//}
//
//void disMarking(int x, int y, int direct) {
//    if(direct == 0) { // up
//        for(int i=x-1;i>=0;i--) {
//            if(office[i][y] == 6)
//                break;
//            else if(office[i][y] < 0)
//                office[i][y]++;
//        }
//    }
//    else if(direct == 1) { // right
//        for(int i=y+1;i<m;i++) {
//            if(office[x][i] == 6)
//                break;
//            else if(office[x][i] < 0)
//                office[x][i]++;
//        }
//    }
//    else if(direct == 2) { // down
//        for(int i=x+1;i<n;i++) {
//            if(office[i][y] == 6)
//                break;
//            else if(office[i][y] < 0)
//                office[i][y]++;
//        }
//    }
//    else { // left
//        for(int i=y-1;i>=0;i--) {
//            if(office[x][i] == 6)
//                break;
//            else if(office[x][i] < 0)
//                office[x][i]++;
//        }
//    }
//}
//
//void cctvView(int x, int y, int type, int d) {
//    if(type == 1) {
//        marking(x, y, d);
//    }
//    else if(type == 2) {
//        marking(x, y, d);
//        marking(x, y, (d+2) % 4);
//    }
//    else if(type == 3) {
//        marking(x, y, d);
//        marking(x, y, (d+1)%4);
//    }
//    else if(type == 4) {
//        marking(x, y, d);
//        if(d == 0)
//            marking(x, y, 3);
//        else
//            marking(x, y, d-1);
//        marking(x, y, (d+1)%4);
//    }
//    else  {
//        for(int i=0;i<4;i++)
//            marking(x, y, i);
//    }
//}
//
//void cctvDisView(int x, int y, int type, int d) { // d = 0, 1, 2, 3
//    if(type == 1) {
//        disMarking(x, y, d);
//    }
//    else if(type == 2) {
//        disMarking(x, y, d);
//        disMarking(x, y, (d+2) % 4);
//    }
//    else if(type == 3) {
//        disMarking(x, y, d);
//        disMarking(x, y, (d+1)%4);
//    }
//    else if(type == 4) {
//        disMarking(x, y, d);
//        if(d == 0)
//            disMarking(x, y, 3);
//        else
//            disMarking(x, y, d-1);
//        disMarking(x, y, (d+1)%4);
//    }
//    else  {
//        for(int i=0;i<4;i++)
//            disMarking(x, y, i);
//    }
//}
//
//void bt(int s) {
//    if(s==pc) {
//        int cnt = 0;
//
//        for(int i=0;i<n;i++) {
//            for(int j=0;j<m;j++) {
//                if(office[i][j] == 0)
//                    cnt++;
//            }
//        }
//
//        if(min_cnt >= cnt) {
//            min_cnt = cnt;
//        }
//
//        return;
//    }
//
//    int cx = cctv[s][0];
//    int cy = cctv[s][1];
//    int type = office[cx][cy];
//
//    if(type == 1 || type == 3 || type == 4) { // 4 case
//        for(int i=0;i<4;i++) {
//            cctvView(cx, cy, type, i);
//            bt(s+1);
//            cctvDisView(cx, cy, type, i);
//        }
//    }
//    else if(type == 2) { // 2 case
//        for(int i=0;i<2;i++) {
//            cctvView(cx, cy, type, i);
//            bt(s+1);
//            cctvDisView(cx, cy, type, i);
//        }
//    }
//    else { // type = 5, only 1 case
//        cctvView(cx, cy, type, 0);
//        bt(s+1);
//        cctvDisView(cx, cy, type, 0);
//    }
//
//}
//
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m;
//
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            cin >> office[i][j];
//            if(office[i][j] > 0 && office[i][j] < 6) {
//                cctv[pc][0] = i;
//                cctv[pc++][1] = j;
//            }
//        }
//    }
//
//    bt(0);
//
//    cout << min_cnt;
//
//    return 0;
//}

/* 감시 <풀이노트>

모든 경우의 수를 다 해본다. (백트래킹으로)
최대 경우의 수

4^8*8*8 정도

1 -> 상, 하, 좌, 우 4 case
2 -> 상하 , 좌우 2 case
3 -> 상, 하, 좌, 우 4 case
4 -> 상, 하, 좌, 우 4 case
5 -> 1 case

음.. 풀면서 N-Queen과 상당히 비슷하다고 느꼈습니다.

처음에 구현했을 때는 마킹/마킹해제 해놓는걸

1. 0을 만나면 -1로 바꾸어 준다.
2. 백트래킹(깊이 들어가기)을 한다.
3. 마킹해놨던걸 해제하기 위해, -1을 만나면 0으로 바꾸어 준다.

였는데, 이러면 공통으로 -1인 부분에서 문제가 생긴다.

예를 들면

1 -1 -1
0  0 -1
0  0  1

처럼 된 경우, 둘이 같은 부분으로 감시 중이다.

여기서 오른쪽 아래 1이 나중인 경우라고 하자. 그럼 백트래킹 다음으로 마킹 해제에서.

1 -1  0
0  0  0
0  0  1

과 같이, '-1을 만나면 0으로 바꾸어준다'는 조건에 의해 아직 왼쪽 위 cctv가 오른쪽으로 쏘고 있음에도
마킹이 해제되어 버리는 문제가 발생했다.

그래서 마킹/마킹해제 과정을 다음과 같이 바꾸었다.

- 0 이하면 빼기 1을 해준다.(마킹)
- 0 미만이면 더하기 1을 해준다. (마킹 해제)

그래서 해당 문제 상황을 해결할 수 있었다.

*/

// BOJ 18808 스티커 붙이기
//#include <iostream>
//
//using namespace std;
//
//int n, m, k;
//bool notebook[40][40];
//int sticker[10][10];
//int tmp[10][10];
//int r, c;
//
//int stick(int x, int y) { // success 0 fail 1
//    for(int i=0;i<r;i++) {
//        for(int j=0;j<c;j++) {
//            if(sticker[i][j]) {
//                if(notebook[x+i][y+j])
//                    return 1;
//            }
//        }
//    }
//
//    for(int i=0;i<r;i++) {
//        for(int j=0;j<c;j++) {
//            if(sticker[i][j]) {
//                notebook[x+i][y+j] = 1;
//            }
//        }
//    }
//
//    return 0;
//}
//
//void rotation() {
//    for(int i=0;i<r;i++) {
//        for(int j=0;j<c;j++) {
//            tmp[j][r-1-i] = sticker[i][j];
//        }
//    }
//
//    for(int i=0;i<c;i++) {
//        for(int j=0;j<r;j++) {
//            sticker[i][j] = tmp[i][j];
//        }
//    }
//
//    int temp = r;
//    r = c;
//    c = temp;
//}
//
//int traversal() {
//    for(int a=0;a<n;a++) {
//        if(a+r > n)
//            break;
//
//        for(int b=0;b<m;b++) {
//            if(b+c > m)
//                break;
//
//             if(!stick(a, b))
//                return 0;
//        }
//    }
//
//    return 1;
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m >> k;
//
//    for(int i=0;i<k;i++) {
//        cin >> r >> c;
//
//        for(int j=0;j<r;j++) {
//            for(int q=0;q<c;q++)
//                cin >> sticker[j][q];
//        }
//
//        for(int a=0;a<4;a++) {
//            if(!traversal()) break;
//            rotation();
//        }
//    }
//
//    int cnt = 0;
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            if(notebook[i][j]) cnt++;
//        }
//    }
//
//    cout << cnt;
//
//    return 0;
//}

/* 스티커 붙이기 <풀이노트>

아, 잘 구현했는데 traversal에서 if(a+r > n)의 위치를 안 쪽 for문 들어가기 전에 놔야하는데
후에 놨어가지고 틀렸었네;;

*/

// BOJ 12100 2048(Easy)
//#include <iostream>
//#include <deque>
//#include <vector>
//#define LINE vector<deque<int>>
//
//using namespace std;
//
//int n;
//int MAX;
//
//void bt(int cnt, int t, LINE row, LINE col) {
//    LINE newRow(20);
//    LINE newCol(20);
//
//    if(t == 0) { // start from top
//        for(int i=0;i<n;i++) {
//            if(col[i].empty()) continue;
//
//            int pr = 0;
//            for(auto c = col[i].begin(); c != col[i].end(); c++) {
//
//                if(c == --col[i].end()) {
//                    newCol[i].push_back(*c);
//                    newRow[pr++].push_back(*c);
//                    continue;
//                }
//
//                if(*c == *(c+1)) {
//                    newCol[i].push_back((*c)*2);
//                    newRow[pr++].push_back((*c)*2);
//                    c++;
//                } else {
//                    newCol[i].push_back(*c);
//                    newRow[pr++].push_back(*c);
//                }
//
//
//            }
//        }
//    } else if(t == 1) { // from left
//        for(int i=0;i<n;i++) {
//            if(row[i].empty()) continue;
//
//            int pc = 0;
//            for(auto r = row[i].begin(); r != row[i].end(); r++) {
//                if(r == --row[i].end()) {
//                    newRow[i].push_back(*r);
//                    newCol[pc++].push_back(*r);
//                    continue;
//                }
//
//                if(*r == *(r+1)) {
//                    newRow[i].push_back((*r)*2);
//                    newCol[pc++].push_back((*r)*2);
//                    r++;
//                } else {
//                    newRow[i].push_back(*r);
//                    newCol[pc++].push_back(*r);
//                }
//            }
//        }
//    } else if(t == 2) { // from down
//        for(int i=0;i<n;i++) {
//            if(col[i].empty()) continue;
//
//            int pr = n-1;
//            for(auto c = --col[i].end();; c--) {
//                if(c == col[i].begin()) {
//                    newCol[i].push_front(*c);
//                    newRow[pr--].push_back(*c);
//                    break;
//                }
//
//                if(*c == *(c-1)) {
//                    newCol[i].push_front((*c)*2);
//                    newRow[pr--].push_back((*c)*2);
//                    c--;
//
//                    if(c == col[i].begin())
//                        break;
//                } else {
//                    newCol[i].push_front(*c);
//                    newRow[pr--].push_back(*c);
//                }
//            }
//        }
//    } else if(t == 3) { // from right
//        for(int i=0;i<n;i++) {
//            if(row[i].empty()) continue;
//
//            int pc = n-1;
//            for(auto r = --row[i].end();; r--) {
//                if(r == row[i].begin()) {
//                    newRow[i].push_front(*r);
//                    newCol[pc--].push_back(*r);
//                    break;
//                }
//
//                if(*r == *(r-1)) {
//                    newRow[i].push_front((*r)*2);
//                    newCol[pc--].push_back((*r)*2);
//                    r--;
//
//                    if(r == row[i].begin())
//                        break;
//                } else {
//                    newRow[i].push_front(*r);
//                    newCol[pc--].push_back(*r);
//                }
//            }
//        }
//    }
//
////    cout << "\nTYPE : " << t << "CNT : " << cnt << "\n";
////
////    cout << "cols: \n";
////    for(int i=0;i<n;i++) {
////        for(auto c : newCol[i])
////            cout << c << " -> ";
////        cout << '\n';
////    }
////
////    cout << "rows: \n";
////    for(int i=0;i<n;i++) {
////        for(auto r : newRow[i])
////            cout << r << " -> ";
////        cout << '\n';
////    }
//
//    if(cnt==4) {
//        for(int i=0;i<n;i++) {
//            if(newRow[i].empty()) continue;
//
//            for(auto r : newRow[i]) {
//                if(MAX < r) MAX = r;
//            }
//        }
//
////        cout << "---------\nMAX: " << MAX << "\n---------\n";
//
//        return;
//    }
//
//    for(int i=0;i<4;i++) { // top, right, down, left
//        bt(cnt+1, i, newRow, newCol);
//    }
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    LINE row(20);
//    LINE col(20);
//
//    cin >> n;
//
//    int v;
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<n;j++) {
//            cin >> v;
//            if(v == 0) continue;
//            row[i].push_back(v);
//            col[j].push_back(v);
//        }
//    }
//
//    for(int i=0;i<4;i++)
//        bt(0, i, row, col);
//
//    cout << MAX;
//
//    return 0;
//}

/* 2048(Easy) <풀이노트>

좀 푸는데 오래걸렸다... 대략 1시간 40분에서 2시간 사이?

처음에 구현하기 전에는 다음과 같이 생각해봤다.

----------------------------------------------
[N][N] size (N <= 20)

1. 상 하 좌 우 경우의수 4,
모든 경우의 수 4x4x4x4x4를 다 해본다.

(리스트?)

2. 어떤 규칙이 있어서, 규칙대로 처리?


1번으로해보면)

백트래킹, 브루트포스.

ex. 왼쪽으로 밀었다.
0번째 행 리스트부터 검사한다. 리스트의 size가 0이면 pass
그럼 각 행의 왼쪽부터 순서대로 다음 숫자와 비교하여
같으면 합쳐서 왼쪽으로 민다.
(그러고 리스트 2개(행 리스트, 열 리스트)에 추가)

--------------------------------------------------

리스트라 적어놧지만 덱을 사용했다. 역방향으로도 넣고 그래야하니까.

1번에서 그냥 배열로 하면 뭔가 시간초과 날거같아서, 처음부터
리스트로 구현을 시도했다. 구현하면서 --를 해줘야하는데 ++을 한다던가,
-1, +1 차이의 실수가 몇 개 있었다. 그래서 시간이 좀 걸렸다. (실수 찾느라)

제출하면서 아 뭔가 시간초과... 안나려나? 했는데 안나서 기모찌햇다.

(오, 나중에 보니 첫 골1문제 솔브였다)

*/

// BOJ 15686 치킨 배달
//#include <iostream>
//#include <algorithm>
//#include <list>
//#include <vector>
//
//#define X first
//#define Y second
//#define MAX 2147483646
//
//using namespace std;
//
//int n, m;
//int city[50][50];
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    list<pair<pair<int, int>, int>> h;
//    int ch[13][2]; // 'c'hicken 'h'ouse
//
//    cin >> n >> m;
//
//    int pch = 0;
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<n;j++) {
//            cin >> city[i][j];
//
//            if(city[i][j] == 1) {
//                h.push_back({{i, j}, MAX});
//            } else if(city[i][j] == 2) {
//                ch[pch][0] = i;
//                ch[pch++][1] = j;
//            }
//        }
//    }
//
//    bool pick[13];
//    fill(pick, pick+13, 1);
//
//    for(int i=0;i<pch-m;i++) {
//        pick[i] = 0;
//    }
//
//    int min_dis = MAX;
//    int xDis;
//    int yDis;
//    do {
//        int sum = 0;
//
//        for(auto it = h.begin(); it != h.end() ; it++) {
//            (*it).Y = MAX;
//        }
//
//        for(int i=0;i<pch;i++) {
//            if(pick[i]) {
//                for(auto it = h.begin(); it != h.end() ; it++) {
//                    sum = abs((*it).X.X - ch[i][0]) + abs((*it).X.Y - ch[i][1]);
//                    if(sum < (*it).Y)
//                        (*it).Y = sum;
//
//                }
//            }
//        }
//
//        int ch_sum = 0;
//        for(auto it : h)
//            ch_sum += it.Y;
//
//        if(ch_sum < min_dis)
//            min_dis = ch_sum;
//
//    } while(next_permutation(pick, pick+pch));
//
//    cout << min_dis;
//
//    return 0;
//}

/* 치킨 배달 <풀이노트>

음.. 구현 자체는 그냥 간단하게 next_permutation을 이용한 조합으로 모든 경우를 고려.

하는 간단한 아이디어 였다.

-----------------------------------------------
집들 담을 queue
치킨집들 담을 배열하나, 좌표를 담아야함.
치킨집을 고를 배열하나(next_permutation용)

조합 돌려서 최솟값 출력.
-----------------------------------------------

근데 구현에서 자꾸만 실수가 발생했는데...

list를 auto it : h 로 사용하니, 실제 리스트의 값이 바뀌지 않음
=> 그냥 auto it = h.begin()... 꼴로 사용함 그랬더니 실제 값이 바뀌어서 해결.

*/

// BOJ 11559 Puyo Puyo
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <list>
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
//    char field[12][6];
//    queue<pair<int, int>> b;
//    int chain = 0;
//
//    for(int i=0;i<12;i++) {
//        for(int j=0;j<6;j++) {
//            cin >> field[i][j];
//            if(field[i][j] != '.') b.push({i, j});
//        }
//    }
//
//    bool isDone = false;
//
//    while(!isDone) {
//        // bfs
//        isDone = 1;
//        bool isReact = false;
//
////        cout << "-------\nnew page: ";
//
//        while(!b.empty()) {
//            pair<int, int> cur = b.front(); b.pop();
//
//            int cx = cur.X;
//            int cy = cur.Y;
//            char cc = field[cx][cy];
//
//            if(cc == '.') continue;
//
////            cout << "start : (" << cx << '.' << cy << ") with " << cc << " || ";
//
//            bool vis[12][6] = {0,};
//            queue<pair<int, int>> cb;
//            list<pair<int, int>> boom;
//            boom.push_back({cx, cy});
//            cb.push({cx, cy});
//            vis[cx][cy] = 1;
//            int successive = 1;
//
//            while(!cb.empty()) {
//                pair<int, int> now = cb.front(); cb.pop();
//
////                cout << "(" << now.X << ',' << now.Y << ") ";
//
//                for(int i=0;i<4;i++) {
//                    int nx = now.X + dx[i];
//                    int ny = now.Y + dy[i];
//
//                    if(nx < 0 || ny < 0 || nx > 11 || ny > 5) continue;
//                    if(field[nx][ny] != cc) continue;
//                    if(vis[nx][ny]) continue;
//
//                    successive++;
//                    vis[nx][ny] = 1;
//                    boom.push_back({nx, ny});
//                    cb.push({nx, ny});
//                }
//            }
//
//            if(successive >= 4) {
//                for(auto it : boom) {
//                    field[it.X][it.Y] = '.';
//                }
//
//                isReact = 1;
//            }
//
////            cout << "\n";
//        }
//
//        if(isReact) chain++;
//
//        // gravity
//        for(int i=10;i>=0;i--) {
//            for(int j=0;j<6;j++) {
//                if(field[i][j] != '.' && field[i+1][j] == '.') {
//                    int nx = i;
//                    while(true) {
//                        nx++;
//
//                        if(nx > 11) break;
//                        if(field[nx][j] != '.') break;
//                    }
//
//                    field[nx-1][j] = field[i][j];
//                    field[i][j] = '.';
//
//                    isDone = false;
//                }
//            }
//        }
//
////        cout << "map: \n";
////        for(int i=0;i<12;i++) {
////            for(int j=0;j<6;j++)
////                cout << field[i][j];
////            cout << "\n";
////        }
////        cout << "\n";
//
//        for(int i=0;i<12;i++) {
//            for(int j=0;j<6;j++) {
//                if(field[i][j] != '.') b.push({i, j});
//            }
//        }
//
//    }
//
//    cout << chain;
//
//    return 0;
//}

/* Puyo Puyo <풀이노트>

아 문제 잘못이해해서 한번 틀렸다.
테트리스마냥 한칸씩 떨어지는게 아니고, 그냥 쭉 떨어지는 거였는데. 잘못 이해했었다.

문제 자체는 간단했다. 범위도 12x6 칸짜리라서 작고.
먼저 bfs를 돌려서 연쇄가 있으면 터트려주고, 그다음 중력을 적용시켜서 떨군다.
이걸 더이상 중력으로인한 변화가 없을 때까지 반복한다.

*/

// BOJ 14891 톱니바퀴
//#include <iostream>
//
//using namespace std;
//
//bool chain[4][8];
//
//void rotation(int num, int dir) {
//
//    if(dir == 1) { // 시계
//        bool last = chain[num][7];
//
//        for(int i=7;i>0;i--)
//            chain[num][i] = chain[num][i-1];
//
//        chain[num][0] = last;
//    }
//    else { // 반시계
//        bool first = chain[num][0];
//
//        for(int i=0;i<7;i++)
//            chain[num][i] = chain[num][i+1];
//
//        chain[num][7] = first;
//    }
//
//}
//
//void bfs(int bef, int cur, int rot) { // rot -1, 0, 1 (0 is no rot)
//    if(cur < 0 || cur > 3) return;
//
//    rot *= -1;
//
//    if(bef > cur) {
//        if(chain[cur][2] != chain[bef][6]) {
//            bfs(cur, cur-1, rot);
//            rotation(cur, rot);
//        }
//    } else {
//        if(chain[cur][6] != chain[bef][2]) {
//            bfs(cur, cur+1, rot);
//            rotation(cur, rot);
//        }
//    }
//}
//
//int main(void) {
////    ios::sync_with_stdio(false);
////    cin.tie(nullptr);
//
//    int k;
//
//    char ipt;
//    for(int i=0;i<4;i++) {
//        for(int j=0;j<8;j++) {
//            cin >> ipt;
//            if(ipt == '1') chain[i][j] = 1;
//            else chain[i][j] = 0;
//        }
//    }
//
//    cin >> k;
//
//    int st, dir;
//
//    while(k--) {
//        cin >> st >> dir;
//
//        st--;
//
//        bfs(st, st+1, dir);
//        bfs(st, st-1, dir);
//
//        rotation(st, dir);
//    }
//
//    int score = 0;
//
//    if(chain[0][0]) score++;
//    if(chain[1][0]) score+=2;
//    if(chain[2][0]) score+=4;
//    if(chain[3][0]) score+=8;
//
//    cout << score;
//
//    return 0;
//}

/* 톱니바퀴 <풀이노트>

문제 구현은 어렵지 않은 편.

--------------------------------
같은 극이면 회전 x
다른 극이여도 둘 다 회전 안했으면 회전 x

시계방향순 입력

회전수 K

번호, 방향(-1 반시계, 1 시계)

[2] 인덱스 = 3시
[6] 인덱스 = 9시

지정한 시계로부터 bfs를 시행한다.

왼쪽시계 -1 인덱스는 왼쪽시계[2] 본인[6]
오른쪽시계 +1 인덱스는 오른쪽[6] 본인[2]

만약 다른 극이고, 회전이 있었다면 -> 그놈도 회전한 것.

시계 저장 배열
회전 플래그를 파라미터로
---------------------------------------

로 구현했는데, 예제가 안맞더라.
이유를 보니 내가 문제 이해를 좀 잘못했다.
나는 해당 톱니바퀴를 돌리고 난 뒤 bfs를 했는데,
bfs를 하고 돌리는 방식이더라..

문제 길면 좀 짜증나는듯

*/

// BOJ 14499 주사위 굴리기
//#include <iostream>
//
//using namespace std;
//
//int _map[20][20];
//int dice[4][3];
//int n, m, x, y;
//
//void roll(int dir) {
//    int top = dice[1][1];
//
//    if(dir == 1) { // east
//        dice[1][1] = dice[1][0];
//        dice[1][0] = dice[3][1];
//        dice[3][1] = dice[1][2];
//        dice[1][2] = top;
//    } else if(dir == 2) { // west
//        dice[1][1] = dice[1][2];
//        dice[1][2] = dice[3][1];
//        dice[3][1] = dice[1][0];
//        dice[1][0] = top;
//    } else if(dir == 4) { // north
//        dice[1][1] = dice[0][1];
//        dice[0][1] = dice[3][1];
//        dice[3][1] = dice[2][1];
//        dice[2][1] = top;
//    } else if(dir == 3) { // south
//        dice[1][1] = dice[2][1];
//        dice[2][1] = dice[3][1];
//        dice[3][1] = dice[0][1];
//        dice[0][1] = top;
//    }
//
//    if(_map[x][y] == 0) _map[x][y] = dice[3][1];
//    else {
//        dice[3][1] = _map[x][y];
//        _map[x][y] = 0;
//    }
//    cout << dice[1][1] << '\n';
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int k;
//
//    cin >> n >> m >> x >> y >> k;
//
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++)
//            cin >> _map[i][j];
//    }
//
//    // east->1, west->2, north->3, south->4
//    while(k--) {
//        int way;
//        cin >> way;
//
//        if(way == 1) {
//            if(y+1 > m-1) continue;
//            y++;
//        } else if(way == 2) {
//            if(y-1 < 0) continue;
//            y--;
//        } else if(way == 3) {
//            if(x-1 < 0) continue;
//            x--;
//        } else if(way == 4) {
//            if(x+1 > n-1) continue;
//            x++;
//        }
//
//        roll(way);
//    }
//
//    return 0;
//}

/* 주사위 굴리기 <풀이노트>

문제 개길다 진짜;;
이게 코딩문제야 독해문제야??

    0
 0 천장 0
    0
   바닥

천장 (1,1)
바닥 (3,1)

상하좌우 구르기를 구현.

나머지는 현재 위치, 다음 위치를 파라미터로
옮기기만 주구장창 하면 됌.

[+1][] -> 남
[-1][] -> 북
=> 가운데 열을 한칸씩 옮기면 댐
남의 경우: 위로
북의 경우: 아래로


[][+1] -> 동
[][-1] -> 서
=> 가운데 행+바닥을 한칸씩 옮기면 댐
동:바닥을 끼니까 순서는 천장->오른쪽0->바닥->왼쪽0->천장
서:천장->왼쪽0->바닥->오른쪽0->천장
모든 명령 수행 시 종료.

다 구현하고 보니, 규칙이 하나 더있더라.
칸에 잇는 수 복사하면 그 칸은 0 되고,
0인 칸이면 바닥면수로 복사시키고...

아오 독해문제네 그냥 이거;;; 어렵지도 않은데

*/

// BOJ 13335 트럭
//#include <iostream>
//#include <queue>
//#include <list>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, w, l;
//    int sum_w = 0;
//    int cnt = 0;
//    queue<int> trucks;
//    list<pair<int, int>> doha;
//
//    cin >> n >> w >> l;
//
//    int ipt;
//    for(int i=0;i<n;i++) {
//        cin >> ipt;
//        trucks.push(ipt);
//    }
//
//    while(!trucks.empty()) {
//        for(auto it = doha.begin();it != doha.end(); it++) {
//            (*it).second--;
//        }
//
//        if(!doha.empty() && (*doha.begin()).second == 0) {
//            sum_w -= (*doha.begin()).first;
//            doha.erase(doha.begin());
//        }
//
//        cnt++;
//
//        int truck = trucks.front();
//
//        if(sum_w + truck > l) continue;
//
//        trucks.pop();
//        sum_w += truck;
//        doha.push_back({truck, w});
//    }
//
//    if(!doha.empty())
//        cnt += doha.back().second;
//
//    cout << cnt;
//
//    return 0;
//}

/* 트럭 <풀이노트>

아 왜이리 구현하는데 실수가 많은지...

1. stl을 참조하기 전에, empty()인지 생각할 것.
2. first, second 참조 헷갈리지 말기.
3. 입력 받을거 입력 받아놧는지 확인.

---------------------------------
n개의 트럭, 한번에 w대의 트럭 올라갈수잇음
최대하중 L >= w의 무게합

한번에 한칸 움직이고, w만큼 움직여야 다리건넘

다리에 가해진 무게 저장 변수,
다리 건너는 과정 리스트. ( 한칸 옮기는걸 -1로 표현, )
queue에 트럭들 넣고,


queue.empty() && list.empty() 이면 종료

while()
	다리 안의 잇는 트럭 건너가기

	다리에 가해진 무게에 (들어갈 트럭)의 무게가 더 크면
	queue에서 꺼내지 않는다.
	=> 아니라면 입장

	cnt++

-----------------------------------

*/

// BOJ 16985 Maaaaaaaaaze
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//typedef struct thrdim {
//    int x, y, z;
//} td;
//
//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, -1, 0, 1};
//int dxz[4] = {0, -1, 0, 1};
//int dyz[4] = {-1, 0, 1, 0};
//int dz[2] = {-1, 1};
//int minDis = 2147483647;
//int **maze[5];
//int ***floors;
//int permu[5] = {0, 1, 2, 3, 4};
//
//void bfs() {
//    int vis[5][5][5] = {0,};
//    queue<td> q;
//
//    td start;
//    start.x = 0;
//    start.y = 0;
//    start.z = 0;
//
//    q.push(start);
//    vis[start.z][start.x][start.y] = 1;
//
//    while(!q.empty()) {
//        td cur = q.front(); q.pop();
//        int cd = vis[cur.z][cur.x][cur.y];
//
//        if(cur.z == 4 && cur.x == 4 && cur.y == 4) {
//            int dis = vis[cur.z][cur.x][cur.z]-1;
//            if(dis < minDis) minDis = dis;
//
////            cout << "---------dis---------\n";
////            for(int i=0;i<5;i++) {
////                cout << i << " floor\n";
////                for(int j=0;j<5;j++) {
////                    for(int k=0;k<5;k++)
////                        cout << vis[i][j][k];
////                    cout << "\n";
////                }
////            }
////            cout << "----------------------\n";
////
////            cout << dis << '\n';
//            return;
//        }
//
//        if(cur.z > 0 && cur.z < 4) { // 가운데 3개 층
//            if(cur.y == 0 || cur.y == 4) {
//                for(int i=0;i<4;i++) {
//                    int nx = cur.x + dx[i];
//                    int nz = cur.z + dxz[i];
//
//                    if(nx < 0 || nz < 0 || nx > 4 || nz > 4) continue;
//                    if(vis[nz][nx][cur.y]) continue;
//                    if(!maze[nz][nx][cur.y]) continue;
//
//                    vis[nz][nx][cur.y] = cd+1;
//                    td next;
//                    next.x = nx;
//                    next.y = cur.y;
//                    next.z = nz;
//                    q.push(next);
//                }
//            } else {
//                for(int i=0;i<4;i++) {
//                    int ny = cur.y + dy[i];
//                    int nz = cur.z + dyz[i];
//
//                    if(ny < 0 || nz < 0 || ny > 4 || nz > 4) continue;
//                    if(vis[nz][cur.x][ny]) continue;
//                    if(!maze[nz][cur.x][ny]) continue;
//
//                    vis[nz][cur.x][ny] = cd+1;
//                    td next;
//                    next.x = cur.x;
//                    next.y = ny;
//                    next.z = nz;
//                    q.push(next);
//                }
//            }
//        } else {
//            if(cur.x == 0 || cur.x == 4 || cur.y == 0 || cur.y == 4) { // 가장자리
//                for(int i=0;i<2;i++) {
//                    int nz = cur.z + dz[i];
//
//                    if(nz < 0 || nz > 4) continue;
//                    if(vis[nz][cur.x][cur.y]) continue;
//                    if(maze[nz][cur.x][cur.y] == 0) continue;
//
//                    vis[nz][cur.x][cur.y] = cd+1;
//                    td next;
//                    next.x = cur.x;
//                    next.y = cur.y;
//                    next.z = nz;
//                    q.push(next);
//                }
//            }
//
//            for(int i=0;i<4;i++) {
//                int nx = cur.x + dx[i];
//                int ny = cur.y + dy[i];
//
//                if(nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
//                if(vis[cur.z][nx][ny]) continue;
//                if(maze[cur.z][nx][ny] == 0) continue;
//
//                vis[cur.z][nx][ny] = cd+1;
//                td next;
//                next.x = nx;
//                next.y = ny;
//                next.z = cur.z;
//                q.push(next);
//            }
//
//        }
//    }
//
//    return;
//}
//
//void rotation(int **m) {
//    int tmp[5][5];
//
//    for(int i=0;i<5;i++) {
//        for(int j=0;j<5;j++)
//            tmp[j][4-i] = m[i][j];
//    }
//
//    for(int i=0;i<5;i++) {
//        for(int j=0;j<5;j++)
//            m[i][j] = tmp[i][j];
//    }
//
//}
//
//void bt(int f) {
//    if(f==5) return;
//
//    for(int i=0;i<4;i++) {
//        rotation(maze[f]);
//        if(maze[0][0][0] && maze[4][4][4]) bfs();
//        bt(f+1);
//    }
//}
//
//int arr[5];
//int fvis[5];
//
//void floor(int c) {
//    if(c==5) {
//        for(int i=0;i<5;i++) {
//            maze[i] = floors[arr[i]];
//        }
//
//        bt(0);
//
//        return;
//    }
//
//    for(int i=0;i<5;i++) {
//        if(!fvis[i]) {
//            fvis[i] = 1;
//            arr[c] = i;
//            floor(c+1);
//            fvis[i] = 0;
//        }
//    }
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    floors = (int***)malloc(sizeof(int**)*5);
//    for(int i=0;i<5;i++) {
//        floors[i] = (int**)malloc(sizeof(int*)*5);
//        for(int j=0;j<5;j++)
//            floors[i][j] = (int*)malloc(sizeof(int)*5);
//    }
//
//    for(int i=0;i<5;i++) {
//        for(int j=0;j<5;j++) {
//            for(int k=0;k<5;k++)
//                cin >> floors[i][j][k];
//        }
//    }
//
//    floor(0);
//
//    if(minDis == 2147483647) cout << -1;
//    else cout << minDis;
//
//    return 0;
//}

/* 어... Maaaaaaaaaze 문제를...
엄청 오랫동안 구현해서 햇는데 예제가 안맞더라고요
그래서 결국 답지를 봣는데
내가 문제를 맘대로 이해해버렷던... 가운데로는, 그러니까
주사위 겉면만 이동 가능한 줄 알앗는데, 안쪽으로도 이동 하더라고요....
아.... 그래서 멘탈나가서 걍 답지 이해하고 끝냇ㄴ슨다...

*/
