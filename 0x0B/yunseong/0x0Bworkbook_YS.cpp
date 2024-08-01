// 1~N까지 합 구현: 강의 중
//#include <iostream>
//
//using namespace std;
//
//int rec(int num) {
//    if(num == 1)
//        return 1;
//
//    return rec(num-1) + num;
//}
//
//int main()
//{
//    int N;
//    cin >> N;
//
//    cout << "sum : " << rec(N);
//
//    return 0;
//}

// BOJ 1629 곱셈
//#include <iostream>
//#define ll long long
//
//using namespace std;
//
//ll get_mod(ll a, ll b, ll c) {
//    if(b <= 1) {
//        return a % c;
//    }
//
//    ll val = get_mod(a, b/2, c);
//
//    val = val * val % c;
//
//    if(b % 2 == 0) return val;
//    else return val * a % c;
//}
//
//int main(void) {
//    ll A, B, C, ans;
//    cin >> A >> B >> C;
//
//    ans = get_mod(A, B, C);
//
//    cout << ans;
//
//    return 0;
//}

/* 아 아니 첫 번째 힌트 보고 나누기2씩하는 분할정복 했는데 안되길래 보니
long long 안해서 틀린거였네... */

// BOJ 11729 하노이 탑 순서
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int cnt;
//queue<pair<int, int>> q;
//
//void hanoi(int n, int s, int d) {
//    cnt++;
//
//    if(n == 1) {
//        q.push({s, d});
//        return;
//    }
//
//    int nextD;
//    if(s+d == 4) nextD = 2;
//    else if(s+d == 3) nextD = 3;
//    else if(s+d == 5) nextD = 1;
//
//
//    hanoi(n-1, s, nextD);
//
//    q.push({s, d});
//
//    hanoi(n-1, nextD, d);
//
//}
//
//
//int main(void) {
//
//    int N;
//    cin >> N;
//
//    hanoi(N, 1, 3);
//
//    cout << cnt << "\n";
//
//    while(!q.empty()) {
//        pair<int, int> cur = q.front(); q.pop();
//        cout << cur.first << ' ' << cur.second << "\n";
//    }
//
//    return 0;
//}

/* 하노이 탑 <풀이노트>

n짜리 기둥을 1에서 3으로 옮긴다고 해보자. 그럼
n-1짜리 기둥을 1에서 2로 옮기고 n을 1에서 3으로 옮긴 뒤,
다시 n-1짜리 기둥을 2에서 3으로 옮긴다.

즉, n짜리를 3으로 옮기고 싶다면, n-1을 '빈자리'에 놓고,
n을 3으로 옮기면 된다. 그리고 다시 n-1을 3으로 옮긴다.
그걸 구현하면 된다.

'빈자리' 값을(nextD) 찾는게 오래걸렸다. 생각해놓고 보니 쉬운데
막상 부딪힐 때는 생각이 안났다.(그게 어려운거긴 함ㅋㅋ)

--- 바킹독 풀이 보고 ---
아 6 - 출발지 - 도착지 해도 되네;;
사실 전에 풀어본적 있는데 저거였다 하고 기억남

*/

// BOJ 1074 Z
//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//int r, w, N, cnt;
//bool isFound = false;
//int target;
//
//void Z(int n, int x, int y) {
//    if(isFound)
//        return;
//
//    if(n==0) {
//        if(x == r && y == w) {
//            target = cnt;
//            isFound = true;
//        }
//        //cout << '(' << x << ',' << y << ')' << "cnt: " << cnt << "\n";
//
//        cnt++;
//        return;
//    }
//
//    int val = pow(2, n-1);
//    int nextX = x + val;
//    int nextY = y + val;
//
//    if((x <= r && r < x+val) && (y <= w && w < y+val))
//        Z(n-1, x, y);
//    cnt += val*val;
//    if((x <= r && r < x+val) && (y+val <= w && w < y+val*2))
//        Z(n-1, x, nextY);
//    cnt += val*val;
//    if((x+val <= r && r < x+val*2) && (y <= w && w < y+val))
//        Z(n-1, nextX, y);
//    cnt += val*val;
//    if((x+val <= r && r < x+val*2) && (y+val <= w && w < y+val*2))
//        Z(n-1, nextX, nextY);
//    cnt += val*val;
//}
//
//int main(void) {
//
//    cin >> N >> r >> w;
//
//    Z(N, 0, 0);
//
//    cout << target;
//
//    return 0;
//}

/* Z <풀이노트>

처음에는 그냥 재귀적으로 그림처럼 모든 칸을 순서대로 들르면서
순서를 누적하고, 해당 좌표에 도착하면 그 순서를 출력하도록 했다.
그랬더니 시간초과.
그래서 해당 좌표 범위로 좁혀가되, 해당 좌표 범위가 아니면서
지나가면 cnt만 한꺼번에 누적하도록 했다.

*/

// BOJ 17479 재귀함수가 뭔가요?
//#include <iostream>
//
//using namespace std;
//int N;
//
//void underBar(int n) {
//    for(int i=0;i<n;i++)
//        cout << "____";
//}
//
//void chatBot(int n) {
//    if(n==N+1) {
//        return;
//    }
//
//    underBar(n-1);
//    cout << "\"재귀함수가 뭔가요?\"\n";
//    underBar(n-1);
//    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
//    underBar(n-1);
//    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
//    underBar(n-1);
//    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
//
//    if(n==N) {
//        underBar(n);
//        cout << "\"재귀함수가 뭔가요?\"\n";
//        underBar(n);
//        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
//        underBar(n);
//        cout << "라고 답변하였지.\n";
//    }
//
//    chatBot(n+1);
//
//    underBar(n-1);
//    cout << "라고 답변하였지.\n";
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> N;
//
//    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
//
//    chatBot(1);
//
//    return 0;
//}

/* 재귀함수가 뭔가요? <풀이노트>

처음에 top-down 방식으로 했다가 아 '라고 답변하였지' 때문에
bottom-up으로 바꾸었다.

*/

// BOJ 1780 종이의 개수
//#include <iostream>
//
//using namespace std;
//
//int mOne, zero, one;
//
//int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
//int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
//
//int cutter(int n, int x, int y, int **paper) {
//
//    if(n==1) {
//        return paper[x][y];
//    }
//
//    int next = n/3;
//    int val[9];
//    bool isNotSame = false;
//    for(int i=0;i<9;i++) {
//        val[i] = cutter(n/3, x+next*dx[i], y+next*dy[i], paper);
//
//        if(i>0 && val[i] != val[i-1])
//            isNotSame = true;
//    }
//
//    if(isNotSame) {
//        if(n>=3) {
//            for(int i=0;i<9;i++) {
//                if(val[i] == -1) {
//                    mOne++;
//                } else if(val[i] == 0) {
//                    zero++;
//                } else if(val[i] == 1) {
//                    one++;
//                }
//            }
//        }
//
//        return 2;
//    }
//    else {
//        if(val[0] == -1) {
//            return -1;
//        } else if(val[0] == 0) {
//            return 0;
//        } else if(val[0] == 1) {
//            return 1;
//        } else {
//            return 2;
//        }
//    }
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//
//    cin >> N;
//
//    int **paper = (int**)malloc(sizeof(int*)*N);
//    for(int i=0;i<N;i++)
//        paper[i] = (int*)malloc(sizeof(int)*N);
//
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N;j++)
//            cin >> paper[i][j];
//    }
//
//    int lastVal = cutter(N, N/2, N/2, paper);
//    if(lastVal != 2) {
//        if(paper[0][0] == -1)
//            mOne++;
//        else if(paper[0][0] == 0)
//            zero++;
//        else
//            one++;
//    }
//
//
//    cout << mOne << "\n";
//    cout << zero << "\n";
//    cout << one;
//
//    return 0;
//}

/* 종이의 개수 <풀이노트>

최대한 분할정복으로 하려고 했다. 여러 번 같은 작업을 하지 않도록.
최대 3^7 * 3^7 짜리 배열이고, 2초의 시간 제한이라서 그렇게 생각했다.

일단 가운데 점을 중심으로 9 영역씩 잘라서 들어간다.
그럼 가장 작은 영역은 한칸짜리, 그담은 9칸짜리일텐데.
당연히 한칸짜리일때 base condition이다. 그때는 그저 해당 칸 값을 return.
그리고 9칸짜리부터가 진짜 분할정복인데.
9칸짜리(n=3) 에서부터는 다음과 같은 작업을 반복한다.
1. 지금 종이를 9분할하여 리턴받은 값들을 비교한다.
2. 전부 같으면 return 해당 (-1, 0, 1 중 하나)
3. 다르면 그 아래 영역 return받은 것들을 바탕으로 -1, 0, 1 카운트를 늘려준다.

2를 리턴하는 경우는 다른 것이 섞인 영역으로, 카운트를 늘려주지 않는다.
전부 달라서, 리턴받은 값이 2이면서 전부 같아지는 경우에는 '다르면(3번 케이)'으로 들어간다.

근데 다른사람들 풀이 보니깐, 그냥 매 분할마다 다 돌아보더라.
그래도 빠르고 시간초과 안나더라. 내가 굳이 어렵게 생각한거였음.

*/

// BOJ 2630 색종이 만들기
//#include <iostream>
//
//using namespace std;
//
//int paper[128][128];
//int white, blue;
//
//void cutter(int n, int x, int y) {
//    if(n==1) {
//        if(paper[x][y] == 0)
//            white++;
//        else
//            blue++;
//
//        return;
//    }
//
//    bool isWhite = false;
//    bool isBlue = false;
//    bool isDiff = false;
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<n;j++) {
//            if(paper[x+i][y+j])
//                isBlue = true;
//            else
//                isWhite = true;
//
//            if(isBlue && isWhite) {
//                isDiff = true;
//                break;
//            }
//        }
//    }
//
//    if(isDiff) {
//        cutter(n/2, x, y);
//        cutter(n/2, x+n/2, y);
//        cutter(n/2, x, y+n/2);
//        cutter(n/2, x+n/2, y+n/2);
//    } else {
//        if(paper[x][y] == 0)
//            white++;
//        else
//            blue++;
//    }
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    cin >> N;
//
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N;j++)
//            cin >> paper[i][j];
//    }
//
//    cutter(N, 0, 0);
//
//    cout << white << "\n" << blue;
//
//    return 0;
//}

/* 색종이 만들기 <풀이노트>

이전 문제에서 얻은 교훈을 바탕으로.
그냥 for문 돌리도록 했다.
이럼 엄청 간단하긴 하다(구현하는게)
이게 시간초과가 안나네.
컴퓨터와 스고이 하야이데스;;

*/

// BOJ 1992 쿼드트리
//#include <iostream>
//
//using namespace std;
//
//int N;
//int video[64][64];
//
//void quad(int n, int x, int y) {
//    if(n==1) {
//        cout << video[x][y];
//        return;
//    }
//
//    bool isNotSame = false;
//    bool isOne = false;
//    bool isZero = false;
//
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<n;j++) {
//            if(video[x+i][y+j])
//                isOne = true;
//            else
//                isZero = true;
//
//            if(isOne && isZero) {
//                isNotSame = true;
//                break;
//            }
//        }
//    }
//
//    if(isNotSame) {
//        cout << '(';
//        quad(n/2, x, y);
//        quad(n/2, x, y+n/2);
//        quad(n/2, x+n/2, y);
//        quad(n/2, x+n/2, y+n/2);
//        cout << ')';
//    }
//    else {
//        if(isOne)
//            cout << '1';
//        else
//            cout << '0';
//    }
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> N;
//
//    char tmp;
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N;j++) {
//            cin >> tmp;
//            video[i][j] = tmp - '0';
//        }
//    }
//
//    quad(N, 0, 0);
//
//    return 0;
//}

/* 쿼드트리 <풀이노트>

4구역씩 구역당 전체검사 재귀로.
다만 전부 같지 않은 구역일 때마다 '( )' 가 추가됌.

*/

// BOJ 2447 별 찍기 - 10
//#include <iostream>
//
//using namespace std;
//
//int N;
//char sky[2187][2187];
//
//int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
//int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
//
//void star(int n, int x, int y) {
//    if(n==1) {
//        sky[x][y] = '*';
//        return;
//    }
//
//    for(int i=0;i<8;i++)
//        star(n/3, x+n/3*dx[i], y+n/3*dy[i]);
//
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> N;
//
//    star(N, N/2, N/2);
//
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N;j++) {
//            if(sky[i][j] == '*')
//                cout << sky[i][j];
//            else
//                cout << ' ';
//        }
//        cout << "\n";
//    }
//
//    return 0;
//}

/* 별 찍기 - 10 <풀이노트>

영역을 9개로 나누었을 때,
가운데 영역은 비어있다.
를 고수하면 된다.

시작 지점은 가운데.

*/

// BOJ 2448 별 찍기 - 11
//#include <iostream>
//
//using namespace std;
//
//char sky[3072][6243];
//
//void star(int n, int x, int y) {
//    if(n==3) {
//        sky[x-1][y] = '*';
//        sky[x][y-1] = '*';
//        sky[x][y+1] = '*';
//        for(int i=0;i<5;i++)
//            sky[x+1][y-2+i] = '*';
//        return;
//    }
//
//    if(n==6) {
//        star(n/2, x-2, y);
//        star(n/2, x+1, y-3);
//        star(n/2, x+1, y+3);
//        return;
//    }
//
//    star(n/2, x-n/4, y);
//    star(n/2, x+n/4, y-n/2);
//    star(n/2, x+n/4, y+n/2);
//}
//
//int main(void) {
//    int N;
//
//    cin >> N;
//
//    star(N, N/2, (N*2-1)/2);
//
//    for(int i=0;i<N;i++) {
//        for(int j=0;j<N*2-1;j++) {
//            if(sky[i][j] == '*')
//                cout << sky[i][j];
//            else
//                cout << ' ';
//        }
//        cout << "\n";
//    }
//
//    return 0;
//}

/* 별 찍기 - 11 <풀이노트>

높이 N
밑변 2*N-1

최대 크기: [3072][6243]

얘도 가운데 기준으로 퍼뜨리면 댐.
가운데: [N/2][(N*2-1)/2]

퍼트리는 건 3방향

위, 좌, 우

위는 x만 N/4만큼
좌-우는 x를 N/4만큼 +하고, y를 +- N/2

N==3일때가 base condition.
N==6일때는 특수하게 퍼트리는게 좀 다름.
위 x만 -2
좌-우는 x를 +1, y를 -+3

*/
