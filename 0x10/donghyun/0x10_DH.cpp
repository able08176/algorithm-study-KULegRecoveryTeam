#include <bits/stdc++.h>
using namespace std;

/* 문제 - 1003 : 피보나치 함수 
int A[41];
int B[41];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    A[0] = 1, A[1] = 0;
    B[0] = 0, B[1] = 1;

    for (int i = 2; i < 41; i++) {
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }

    int n;
    cin >> n;

    while (n--) {
        int k;
        cin >> k;
        cout << A[k] << " " << B[k] << "\n";
    }
}
*/

/* 문제 - 1932 : 정수삼각형
int triangle[500][500];
int mtr[500][500];
int n;
int ans = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 500; i++) fill(triangle[i], triangle[i] + 500, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> triangle[i][j];
        }
    }

    mtr[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) mtr[i][j] = mtr[i - 1][j] + triangle[i][j];
            else if (j == i) mtr[i][j] = mtr[i - 1][j - 1] + triangle[i][j];
            else mtr[i][j] = max(mtr[i - 1][j - 1], mtr[i - 1][j]) + triangle[i][j];
        }
    }

    for (int i = 0; i < n; i++) ans = max(ans, mtr[n - 1][i]);
    cout << ans;
}
*/
/* 문제 - 11727 : 2n타일링2 
int D[1001];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    D[0] = 1;
    D[1] = 1;
    cin >> n;
    for (int i = 2; i < n + 1; i++) D[i] = (D[i - 1] + D[i - 2] * 2) % 10007;
    cout << D[n];
}
*/

/* 문제 - 2193 : 이천수 
long long D[91][2];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    D[1][0] = 0;
    D[1][1] = 1;
    for (int i = 2; i < n+1; i++) {
        D[i][0] = D[i-1][0] 
        
        + D[i-1][1];
        D[i][1] = D[i-1][0];
    }
    cout << D[n][0] + D[n][1];
}
*/

/* 문제 - 1912 : 연속합
int n;
int ans = -1000;
int A[100001];
int B[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    B[0] = 0;
    cin >> n;

    for (int i = 1; i < n + 1; i++) { 
        cin >> A[i];
        B[i] = max(0, B[i - 1]) + A[i];
    }

    for (int i = 1; i < n + 1; i++) ans = max(ans, B[i]);

    cout << ans;
}
*/
/* 문제 - 11055 : 가장 큰 증가하는 부분 수열 
int n;
int mx = 0;
int A[1001];
int B[1001];
int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(B, B + 1001, 0);
    for (int i = 1; i < n + 1; i++) {
        cin >> A[i];
        B[i] = A[i];
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < i + 1; j++) {
            if (A[j] < A[i]) B[i] = max(B[i], B[j] + A[i]);
        }
    }
    
    for (int i = 1; i < n + 1; i++) mx = max(mx, B[i]);
    cout << mx;
}
*/

/* 문제 - 11053 : 가장 긴 증가하는 부분 수열 
int n;
int mx = 0;
int A[1001];
int B[1001];
int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(B, B + 1001, 1);
    for (int i = 1; i < n + 1; i++) {
        cin >> A[i];
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < i + 1; j++) {
            if (A[j] < A[i]) B[i] = max(B[i], B[j] + 1);
        }
    }

    for (int i = 1; i < n + 1; i++) mx = max(mx, B[i]);
    cout << mx;
}
*/

/* 문제 - 9461 : 파도반 수열
long long P[101];
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;

    for (int i = 6; i < 101; i++) P[i] = P[i - 1] + P[i - 5];
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        cout << P[m] << "\n";
    }
}
*/

/* 문제 - 14501 : 퇴사 
int n;
int p[17];
int t[17];
int ans[17];
int mx = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(ans, ans + 17, 0);
    for (int i = 1; i < n + 1; i++) cin >> t[i] >> p[i];

    for (int i = n; i > 0; i--) {
        if (t[i] + i < n + 2) ans[i] = max(ans[i + t[i]] + p[i], ans[i + 1]);
        else ans[i] = ans[i + 1];
    }

    for (int i = 1; i < n + 2; i++) mx = max(mx, ans[i]);
    cout << mx;
}
*/

/* 문제 - 15486 : 퇴사-2 
int n;
int p[1500002];
int t[1500002];
int ans[1500002];
int mx = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(ans, ans + 17, 0);
    for (int i = 1; i < n + 1; i++) cin >> t[i] >> p[i];

    for (int i = n; i > 0; i--) {
        if (t[i] + i < n + 2) ans[i] = max(ans[i + t[i]] + p[i], ans[i + 1]);
        else ans[i] = ans[i + 1];
    }

    for (int i = 1; i < n + 2; i++) mx = max(mx, ans[i]);
    cout << mx;
}
*/

/* 문제 - 10844 : 쉬운 계단 수 */
int n;
long long ans = 0;
long long num[101][10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < 10; i++) num[1][i] = 1;
    num[1][0] = 0;
    cin >> n;
    for (int i = 2; i < n + 1; i++) {
        num[i][0] = num[i - 1][1];
        num[i][9] = num[i - 1][8];
        for (int j = 1; j < 9; j++) {
            num[i][j] = num[i - 1][j - 1] + num[i - 1][j + 1];
        }
        for (int j = 0; j < 10; j++) num[i][j] %= 1000000000;
    }
    for (int i = 0; i < 10; i++) ans += num[n][i];
    ans %= 1000000000;    
    cout << ans;
}

/* 문제 - 9251 : LCS */
