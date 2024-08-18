// BOJ 15683 ����
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

/* ���� <Ǯ�̳�Ʈ>

��� ����� ���� �� �غ���. (��Ʈ��ŷ����)
�ִ� ����� ��

4^8*8*8 ����

1 -> ��, ��, ��, �� 4 case
2 -> ���� , �¿� 2 case
3 -> ��, ��, ��, �� 4 case
4 -> ��, ��, ��, �� 4 case
5 -> 1 case

��.. Ǯ�鼭 N-Queen�� ����� ����ϴٰ� �������ϴ�.

ó���� �������� ���� ��ŷ/��ŷ���� �س��°�

1. 0�� ������ -1�� �ٲپ� �ش�.
2. ��Ʈ��ŷ(���� ����)�� �Ѵ�.
3. ��ŷ�س����� �����ϱ� ����, -1�� ������ 0���� �ٲپ� �ش�.

���µ�, �̷��� �������� -1�� �κп��� ������ �����.

���� ���

1 -1 -1
0  0 -1
0  0  1

ó�� �� ���, ���� ���� �κ����� ���� ���̴�.

���⼭ ������ �Ʒ� 1�� ������ ����� ����. �׷� ��Ʈ��ŷ �������� ��ŷ ��������.

1 -1  0
0  0  0
0  0  1

�� ����, '-1�� ������ 0���� �ٲپ��ش�'�� ���ǿ� ���� ���� ���� �� cctv�� ���������� ��� ��������
��ŷ�� �����Ǿ� ������ ������ �߻��ߴ�.

�׷��� ��ŷ/��ŷ���� ������ ������ ���� �ٲپ���.

- 0 ���ϸ� ���� 1�� ���ش�.(��ŷ)
- 0 �̸��̸� ���ϱ� 1�� ���ش�. (��ŷ ����)

�׷��� �ش� ���� ��Ȳ�� �ذ��� �� �־���.

*/

// BOJ 18808 ��ƼĿ ���̱�
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

/* ��ƼĿ ���̱� <Ǯ�̳�Ʈ>

��, �� �����ߴµ� traversal���� if(a+r > n)�� ��ġ�� �� �� for�� ���� ���� �����ϴµ�
�Ŀ� ������� Ʋ�Ⱦ���;;

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

/* 2048(Easy) <Ǯ�̳�Ʈ>

�� Ǫ�µ� �����ɷȴ�... �뷫 1�ð� 40�п��� 2�ð� ����?

ó���� �����ϱ� ������ ������ ���� �����غô�.

----------------------------------------------
[N][N] size (N <= 20)

1. �� �� �� �� ����Ǽ� 4,
��� ����� �� 4x4x4x4x4�� �� �غ���.

(����Ʈ?)

2. � ��Ģ�� �־, ��Ģ��� ó��?


1�������غ���)

��Ʈ��ŷ, ���Ʈ����.

ex. �������� �о���.
0��° �� ����Ʈ���� �˻��Ѵ�. ����Ʈ�� size�� 0�̸� pass
�׷� �� ���� ���ʺ��� ������� ���� ���ڿ� ���Ͽ�
������ ���ļ� �������� �δ�.
(�׷��� ����Ʈ 2��(�� ����Ʈ, �� ����Ʈ)�� �߰�)

--------------------------------------------------

����Ʈ�� ����J���� ���� ����ߴ�. ���������ε� �ְ� �׷����ϴϱ�.

1������ �׳� �迭�� �ϸ� ���� �ð��ʰ� ���Ű��Ƽ�, ó������
����Ʈ�� ������ �õ��ߴ�. �����ϸ鼭 --�� ������ϴµ� ++�� �Ѵٴ���,
-1, +1 ������ �Ǽ��� �� �� �־���. �׷��� �ð��� �� �ɷȴ�. (�Ǽ� ã����)

�����ϸ鼭 �� ���� �ð��ʰ�... �ȳ�����? �ߴµ� �ȳ��� ������޴�.

(��, ���߿� ���� ù ��1���� �ֺ꿴��)

*/

// BOJ 15686 ġŲ ���
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

/* ġŲ ��� <Ǯ�̳�Ʈ>

��.. ���� ��ü�� �׳� �����ϰ� next_permutation�� �̿��� �������� ��� ��츦 ���.

�ϴ� ������ ���̵�� ����.

-----------------------------------------------
���� ���� queue
ġŲ���� ���� �迭�ϳ�, ��ǥ�� ��ƾ���.
ġŲ���� �� �迭�ϳ�(next_permutation��)

���� ������ �ּڰ� ���.
-----------------------------------------------

�ٵ� �������� �ڲٸ� �Ǽ��� �߻��ߴµ�...

list�� auto it : h �� ����ϴ�, ���� ����Ʈ�� ���� �ٲ��� ����
=> �׳� auto it = h.begin()... �÷� ����� �׷����� ���� ���� �ٲ� �ذ�.

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

/* Puyo Puyo <Ǯ�̳�Ʈ>

�� ���� �߸������ؼ� �ѹ� Ʋ�ȴ�.
��Ʈ�������� ��ĭ�� �������°� �ƴϰ�, �׳� �� �������� �ſ��µ�. �߸� �����߾���.

���� ��ü�� �����ߴ�. ������ 12x6 ĭ¥���� �۰�.
���� bfs�� ������ ���Ⱑ ������ ��Ʈ���ְ�, �״��� �߷��� ������Ѽ� ������.
�̰� ���̻� �߷��������� ��ȭ�� ���� ������ �ݺ��Ѵ�.

*/

// BOJ 14891 ��Ϲ���
//#include <iostream>
//
//using namespace std;
//
//bool chain[4][8];
//
//void rotation(int num, int dir) {
//
//    if(dir == 1) { // �ð�
//        bool last = chain[num][7];
//
//        for(int i=7;i>0;i--)
//            chain[num][i] = chain[num][i-1];
//
//        chain[num][0] = last;
//    }
//    else { // �ݽð�
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

/* ��Ϲ��� <Ǯ�̳�Ʈ>

���� ������ ����� ���� ��.

--------------------------------
���� ���̸� ȸ�� x
�ٸ� ���̿��� �� �� ȸ�� �������� ȸ�� x

�ð����� �Է�

ȸ���� K

��ȣ, ����(-1 �ݽð�, 1 �ð�)

[2] �ε��� = 3��
[6] �ε��� = 9��

������ �ð�κ��� bfs�� �����Ѵ�.

���ʽð� -1 �ε����� ���ʽð�[2] ����[6]
�����ʽð� +1 �ε����� ������[6] ����[2]

���� �ٸ� ���̰�, ȸ���� �־��ٸ� -> �׳� ȸ���� ��.

�ð� ���� �迭
ȸ�� �÷��׸� �Ķ���ͷ�
---------------------------------------

�� �����ߴµ�, ������ �ȸ´���.
������ ���� ���� ���� ���ظ� �� �߸��ߴ�.
���� �ش� ��Ϲ����� ������ �� �� bfs�� �ߴµ�,
bfs�� �ϰ� ������ ����̴���..

���� ��� �� ¥�����µ�

*/

// BOJ 14499 �ֻ��� ������
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

/* �ֻ��� ������ <Ǯ�̳�Ʈ>

���� ����� ��¥;;
�̰� �ڵ������� ���ع�����??

    0
 0 õ�� 0
    0
   �ٴ�

õ�� (1,1)
�ٴ� (3,1)

�����¿� �����⸦ ����.

�������� ���� ��ġ, ���� ��ġ�� �Ķ���ͷ�
�ű�⸸ �ֱ���â �ϸ� ��.

[+1][] -> ��
[-1][] -> ��
=> ��� ���� ��ĭ�� �ű�� ��
���� ���: ����
���� ���: �Ʒ���


[][+1] -> ��
[][-1] -> ��
=> ��� ��+�ٴ��� ��ĭ�� �ű�� ��
��:�ٴ��� ���ϱ� ������ õ��->������0->�ٴ�->����0->õ��
��:õ��->����0->�ٴ�->������0->õ��
��� ��� ���� �� ����.

�� �����ϰ� ����, ��Ģ�� �ϳ� ���ִ���.
ĭ�� �մ� �� �����ϸ� �� ĭ�� 0 �ǰ�,
0�� ĭ�̸� �ٴڸ���� �����Ű��...

�ƿ� ���ع����� �׳� �̰�;;; ������� ������

*/

// BOJ 13335 Ʈ��
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

/* Ʈ�� <Ǯ�̳�Ʈ>

�� ���̸� �����ϴµ� �Ǽ��� ������...

1. stl�� �����ϱ� ����, empty()���� ������ ��.
2. first, second ���� �򰥸��� ����.
3. �Է� ������ �Է� �޾ƇJ���� Ȯ��.

---------------------------------
n���� Ʈ��, �ѹ��� w���� Ʈ�� �ö󰥼�����
�ִ����� L >= w�� ������

�ѹ��� ��ĭ �����̰�, w��ŭ �������� �ٸ��ǳ�

�ٸ��� ������ ���� ���� ����,
�ٸ� �ǳʴ� ���� ����Ʈ. ( ��ĭ �ű�°� -1�� ǥ��, )
queue�� Ʈ���� �ְ�,


queue.empty() && list.empty() �̸� ����

while()
	�ٸ� ���� �մ� Ʈ�� �ǳʰ���

	�ٸ��� ������ ���Կ� (�� Ʈ��)�� ���԰� �� ũ��
	queue���� ������ �ʴ´�.
	=> �ƴ϶�� ����

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
//        if(cur.z > 0 && cur.z < 4) { // ��� 3�� ��
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
//            if(cur.x == 0 || cur.x == 4 || cur.y == 0 || cur.y == 4) { // �����ڸ�
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

/* ��... Maaaaaaaaaze ������...
��û �������� �����ؼ� �޴µ� ������ �ȸ´�����
�׷��� �ᱹ ������ �f�µ�
���� ������ ����� �����ع��Ǵ�... ����δ�, �׷��ϱ�
�ֻ��� �Ѹ鸸 �̵� ������ �� �˾Ѵµ�, �������ε� �̵� �ϴ�����....
��.... �׷��� ��Ż������ �� ���� �����ϰ� ����������...

*/
