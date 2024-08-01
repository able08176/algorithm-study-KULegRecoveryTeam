// 1~N���� �� ����: ���� ��
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

// BOJ 1629 ����
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

/* �� �ƴ� ù ��° ��Ʈ ���� ������2���ϴ� �������� �ߴµ� �ȵǱ淡 ����
long long ���ؼ� Ʋ���ſ���... */

// BOJ 11729 �ϳ��� ž ����
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

/* �ϳ��� ž <Ǯ�̳�Ʈ>

n¥�� ����� 1���� 3���� �ű�ٰ� �غ���. �׷�
n-1¥�� ����� 1���� 2�� �ű�� n�� 1���� 3���� �ű� ��,
�ٽ� n-1¥�� ����� 2���� 3���� �ű��.

��, n¥���� 3���� �ű�� �ʹٸ�, n-1�� '���ڸ�'�� ����,
n�� 3���� �ű�� �ȴ�. �׸��� �ٽ� n-1�� 3���� �ű��.
�װ� �����ϸ� �ȴ�.

'���ڸ�' ����(nextD) ã�°� �����ɷȴ�. �����س��� ���� ���
���� �ε��� ���� ������ �ȳ���.(�װ� �����ű� �Ԥ���)

--- ��ŷ�� Ǯ�� ���� ---
�� 6 - ����� - ������ �ص� �ǳ�;;
��� ���� Ǯ��� �ִµ� ���ſ��� �ϰ� ��ﳲ

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

/* Z <Ǯ�̳�Ʈ>

ó������ �׳� ��������� �׸�ó�� ��� ĭ�� ������� �鸣�鼭
������ �����ϰ�, �ش� ��ǥ�� �����ϸ� �� ������ ����ϵ��� �ߴ�.
�׷����� �ð��ʰ�.
�׷��� �ش� ��ǥ ������ ��������, �ش� ��ǥ ������ �ƴϸ鼭
�������� cnt�� �Ѳ����� �����ϵ��� �ߴ�.

*/

// BOJ 17479 ����Լ��� ������?
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
//    cout << "\"����Լ��� ������?\"\n";
//    underBar(n-1);
//    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
//    underBar(n-1);
//    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
//    underBar(n-1);
//    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
//
//    if(n==N) {
//        underBar(n);
//        cout << "\"����Լ��� ������?\"\n";
//        underBar(n);
//        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
//        underBar(n);
//        cout << "��� �亯�Ͽ���.\n";
//    }
//
//    chatBot(n+1);
//
//    underBar(n-1);
//    cout << "��� �亯�Ͽ���.\n";
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> N;
//
//    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
//
//    chatBot(1);
//
//    return 0;
//}

/* ����Լ��� ������? <Ǯ�̳�Ʈ>

ó���� top-down ������� �ߴٰ� �� '��� �亯�Ͽ���' ������
bottom-up���� �ٲپ���.

*/

// BOJ 1780 ������ ����
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

/* ������ ���� <Ǯ�̳�Ʈ>

�ִ��� ������������ �Ϸ��� �ߴ�. ���� �� ���� �۾��� ���� �ʵ���.
�ִ� 3^7 * 3^7 ¥�� �迭�̰�, 2���� �ð� �����̶� �׷��� �����ߴ�.

�ϴ� ��� ���� �߽����� 9 ������ �߶� ����.
�׷� ���� ���� ������ ��ĭ¥��, �״��� 9ĭ¥�����ٵ�.
�翬�� ��ĭ¥���϶� base condition�̴�. �׶��� ���� �ش� ĭ ���� return.
�׸��� 9ĭ¥�����Ͱ� ��¥ ���������ε�.
9ĭ¥��(n=3) �������ʹ� ������ ���� �۾��� �ݺ��Ѵ�.
1. ���� ���̸� 9�����Ͽ� ���Ϲ��� ������ ���Ѵ�.
2. ���� ������ return �ش� (-1, 0, 1 �� �ϳ�)
3. �ٸ��� �� �Ʒ� ���� return���� �͵��� �������� -1, 0, 1 ī��Ʈ�� �÷��ش�.

2�� �����ϴ� ���� �ٸ� ���� ���� ��������, ī��Ʈ�� �÷����� �ʴ´�.
���� �޶�, ���Ϲ��� ���� 2�̸鼭 ���� �������� ��쿡�� '�ٸ���(3�� ����)'���� ����.

�ٵ� �ٸ������ Ǯ�� ���ϱ�, �׳� �� ���Ҹ��� �� ���ƺ�����.
�׷��� ������ �ð��ʰ� �ȳ�����. ���� ���� ��ư� �����Ѱſ���.

*/

// BOJ 2630 ������ �����
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

/* ������ ����� <Ǯ�̳�Ʈ>

���� �������� ���� ������ ��������.
�׳� for�� �������� �ߴ�.
�̷� ��û �����ϱ� �ϴ�(�����ϴ°�)
�̰� �ð��ʰ��� �ȳ���.
��ǻ�Ϳ� ������ �Ͼ��̵���;;

*/

// BOJ 1992 ����Ʈ��
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

/* ����Ʈ�� <Ǯ�̳�Ʈ>

4������ ������ ��ü�˻� ��ͷ�.
�ٸ� ���� ���� ���� ������ ������ '( )' �� �߰���.

*/

// BOJ 2447 �� ��� - 10
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

/* �� ��� - 10 <Ǯ�̳�Ʈ>

������ 9���� �������� ��,
��� ������ ����ִ�.
�� ����ϸ� �ȴ�.

���� ������ ���.

*/

// BOJ 2448 �� ��� - 11
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

/* �� ��� - 11 <Ǯ�̳�Ʈ>

���� N
�غ� 2*N-1

�ִ� ũ��: [3072][6243]

�굵 ��� �������� �۶߸��� ��.
���: [N/2][(N*2-1)/2]

��Ʈ���� �� 3����

��, ��, ��

���� x�� N/4��ŭ
��-��� x�� N/4��ŭ +�ϰ�, y�� +- N/2

N==3�϶��� base condition.
N==6�϶��� Ư���ϰ� ��Ʈ���°� �� �ٸ�.
�� x�� -2
��-��� x�� +1, y�� -+3

*/
