#include <bits/stdc++.h>
using namespace std;


/* 문제 - 17478번 : 재귀함수가 뭔가요?
int n;
void func1(int num) {
    string str = "";
    for (int i = 0; i < 4 * num; i++) str += "_";

    cout << str << "\"재귀함수가 뭔가요?\"\n";

    if (num == n) {
        cout << str << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    }
    else {
        cout << str << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        cout << str << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        cout << str << "그의 답은 대부분 옳았다고 하네.그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        func1(num + 1);
    }
    cout << str << "라고 답변하였지.\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    func1(0);
}
*/

/* 문제 - 1780번 : 종이의 개수.
int p[3000][3000];
int n,a = 0, b = 0, c = 0;

void func1(int x, int y, int num){

    bool flag = true;

    for (int i = x; i < x + num; i++) {
        for (int j = y; j < y + num; j++) {
            if (p[x][y] != p[i][j]) {
                flag = false;
            }
        }
    }

    if (flag) {
        if (p[x][y] == -1) a += 1;
        else if (p[x][y] == 0) b += 1;
        else c += 1;
        return;
    }

    num /= 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) func1(x + i * num, y + j * num, num);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> p[i][j];
    }
    func1(0,0,n);
    cout << a << "\n" << b << "\n" << c << "\n";
}

*/

/* 문제 - 2630번 : 색종이 만들기
int p[200][200];
int n, a = 0, b = 0;

void func1(int x, int y, int num) {

    bool flag = true;

    for (int i = x; i < x + num; i++) {
        for (int j = y; j < y + num; j++) {
            if (p[x][y] != p[i][j]) {
                flag = false;
            }
        }
    }

    if (flag) {
        if (p[x][y] == 0) a += 1;
        else b += 1;
        return;
    }

    num /= 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) func1(x + i * num, y + j * num, num);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> p[i][j];
    }
    func1(0, 0, n);
    cout << a << "\n" << b << "\n";
}
*/

/* 문제 - 1992번 : 쿼드트리
char p[100][100];
int n;

void func1(int x, int y, int num) {

    bool flag = true;

    for (int i = x; i < x + num; i++) {
        for (int j = y; j < y + num; j++) {
            if (p[x][y] != p[i][j]) {
                flag = false;
            }
        }
    }

    if (flag) {
        if (p[x][y] == '0') cout << '0';
        else cout << '1';
        return;
    }

    num /= 2;
    cout << '(';

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) func1(x + i * num, y + j * num, num);
    }
    cout << ')';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> p[i][j];
    }
    func1(0, 0, n);
}
*/

/* 문제 - 1992번 : 별찍기 - 10
char p[3000][3000];
int n;
void func1(int x, int y, int num) {

    if (num == 1) return;
    num /= 3;

    for (int i = x + num; i < x + 2 * num; i++) {
        for (int j = y + num; j < y + 2 * num; j++) {        
            p[i][j] = ' ';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) func1(x + i * num, y + j * num, num);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) fill(p[i], p[i] + n, '*');
    func1(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << p[i][j];
        }
        cout << "\n";
    }
}
*/

// 문제 - 2448 : 별찍기
void func1(int n, int i, int j) {
    if (j <= 2 * i) {
        if (n == 3 && !(i == 1 && j == 1)) cout << '*';
        else func1(n / 2, i % (n / 2), j % n);
    }
    else cout << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << string(n - i - 1, ' ');
        for (int j = 0; j <= n + i; j++)
            func1(n, i, j);
        cout << '\n';
    }
}

// 2448번 답지 참고함
