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
