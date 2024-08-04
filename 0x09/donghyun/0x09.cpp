#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

/* 문제 : 1012 - 유기농 배추
int board[51][51];
bool vis[51][51];
int k, a, b, m, n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;

void bfs(int w, int e) {
	vis[w][e] = true;
	Q.push({ w,e });
	while (!Q.empty()) {
		pair<int, int> p = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = p.X + dx[dir];
			int ny = p.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int d;
	cin >> d;
	while (d--) {
		int num = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(vis[i], vis[i] + m, false);
		}
		while (k--) {
			cin >> a >> b;
			board[b][a] = 1;
		}
		for (int w = 0; w < n; w++) {
			for (int e = 0; e < m; e++) {
				if (board[w][e] == 1 && !vis[w][e]) {
					num++;
					bfs(w, e);
				}
			}
		}
		cout << num << "\n";
	}
}

// BFS 문제 유형1 : 개수세기
// 풀이법 : 반복문 이용 -> 뚫려있는 아직 가지않은 타일 찾기(조건문) -> BFS실행(함수) -> 개수증가
// board배열 : 타일의 종류를 가리는 배열 
// vis배열 : 지나온 타일인지 확인하는 배열

*/
/*
// 문제 10026 - 적록색약
char board[101][101];
bool vis[101][101];
int n, num1=0, num2=0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;

void bfs(int w, int e) {
	vis[w][e] = true;
	Q.push({ w,e });
	while (!Q.empty()) {
		pair<int, int> p = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = p.X + dx[dir];
			int ny = p.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] || board[nx][ny] != board[w][e]) continue;
			vis[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				bfs(i, j);
				num1++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + n, false);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'R') board[i][j] = 'G';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				bfs(i, j);
				num2++;
			}
		}
	}

	cout << num1 << " " << num2;
}

// 문제 1012 - 유기농 배추 문제랑 별차이 없음(오히러 벽이 없기때문에, 조건이 더 간단해짐)
*/

/*
// 문제 7569 - 토마토
int board[101][101][101];
int dist[101][101][101];
int m,n,h, ans = 0;
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<tuple<int,int,int>> Q;

void bfs() {
	while (!Q.empty()) {
		tuple<int, int, int> t = Q.front();
		Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = get<0>(t) + dx[dir];
			int ny = get<1>(t) + dy[dir];
			int nz = get<2>(t) + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
			Q.push({ nx,ny,nz });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[j][k][i];
				if (board[j][k][i] == 1) {
					Q.push({ j,k,i });
				}
				if (board[j][k][i] == 0) {
					dist[j][k][i] = -1;
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[j][k][i] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
		}
	}
	cout << ans;
}

// BFS문제유형2 : 탐색까지의 소요 시간
// 만약 익은 토마토의 경우, 큐에 push / 만약 익지 않은 토마토의 경우, dist배열(소요시간 기록배열)을 -1로 초기화
// bfs진행 이때, dist배열을 vis배열 처럼 이용가능
// 3차원의 경우, pair대신 tuple을 이용
// 풀이법 : 출발지점을 미리 큐에 push해 놓음으로서 쉽게 해결 가능

*/ 
/*
// 문제 7562번 - 나이트의 이동

int dist[301][301];
int I, x11, y11, x22, y22, ans = 0;
int dx[8] = { 1,2,1,2,-1,-2,-1,-2 };
int dy[8] = { 2,1,-2,-1,2,1,-2,-1 };
queue<pair<int, int>> Q;

void bfs(int w, int e) {
	dist[w][e] = 0;
	Q.push({ w,e });
	while (!Q.empty()) {
		pair<int, int> p = Q.front();
		Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = p.X + dx[dir];
			int ny = p.Y + dy[dir];
			if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[p.X][p.Y] + 1;
			Q.push({ nx,ny });
			if (dist[x22][y22] >= 0) {
				ans = dist[x22][y22];
				break;
			}
		}
	}
}

// 문제 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	while (num--) {
		cin >> I;
		for (int i = 0; i < I; i++) {
			fill(dist[i], dist[i] + I, -1);
		}
		cin >> x11 >> y11;
		cin >> x22 >> y22;
		bfs(x11, y11);
		cout << ans << "\n";
	}

}
*/
// 최단시간 소요 문제 -> 풀이법 토마토 문제와 동일
// 이동하는 방법이 다르므로 dx,dy만 수정해주면 됨
// 벽이 없으므로 board배열은 필요없음, dist만 이용

/* 문제 : 5427 - 불 
string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

void bfs1() {
	while (!q1.empty()) {
		auto cur = q1.front();
		q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			q1.push({ nx, ny });
		}
	}
}
int bfs2() {
	while (!q2.empty()) {
		auto cur = q2.front();
		q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				return dist2[cur.X][cur.Y] + 1;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist2[cur.X][cur.Y]+1 >= dist1[nx][ny]) continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			q2.push({nx, ny});
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	while (num--) {
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			fill(dist1[i], dist1[i] + m, -1);
			fill(dist2[i], dist2[i] + m, -1);
		}
		for (int i = 0; i < n; i++) {
			cin >> board[i];
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '*') {
					q1.push({ i,j });
					dist1[i][j] = 0;
				}
				if (board[i][j] == '@') {
					q2.push({ i,j });
					dist2[i][j] = 0;
				}
			}
		}
		bfs1();
		int ans = bfs2();
		if (ans == -1) cout << "IMPOSSIBLE" << "\n";
		else cout << ans << "\n";
		while(!q1.empty())   q1.pop();
		while(!q2.empty())   q2.pop();
	}
}
*/
/* 문제 : 2206 - 벽부수고 이동하기
char board[1001][1001];
int dis[1001][1001];
int flag[1001][1001];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<tuple<int, int, int>> Q;

int bfs(int w, int e) {
	if (n == 1 && m == 1) return 1;
	Q.push({ w,e,0 });
	while (!Q.empty()) {
		tuple<int, int, int> t = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = get<0>(t) + dx[dir];
			int ny = get<1>(t) + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (flag[nx][ny] == 2) continue;
			if (dis[nx][ny] >= 0 && get<2>(t) == 1 && flag[nx][ny] == 1) continue;
			if (dis[nx][ny] >= 0 && get<2>(t) == 1 && flag[nx][ny] == 0) flag[nx][ny] = 1;
			if (dis[nx][ny] >= 0 && get<2>(t) == 0) flag[nx][ny] = 2;
			if (board[nx][ny] == '1' && get<2>(t) == 1) continue;
			if (board[nx][ny] == '1' && get<2>(t) == 0) {
				dis[nx][ny] = dis[get<0>(t)][get<1>(t)] + 1;
				Q.push({ nx,ny,1 });
				continue;
			}
			dis[nx][ny] = dis[get<0>(t)][get<1>(t)] + 1;
			if(get<2>(t) == 0) Q.push({ nx,ny,0 });
			else Q.push({ nx,ny,1 });
			if (dis[n - 1][m - 1] >= 0) {
				return dis[n - 1][m - 1] + 1;
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) fill(dis[i], dis[i] + m, -1);
	for (int i = 0; i < n; i++) fill(flag[i], flag[i] + m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	dis[0][0] = 0;
	cout << bfs(0, 0);
}

// 최소 거리 구하는 BFS문제 
// 기존의 문제와 다른점 : 벽을 한번 뚫을 수 있음
// 생각 : 벽을 한번만 뚫을 수 있으니 큐를 튜플 자료형으로 생성해서 벽을 뚫었는지 여부를 저장하자
// --> 실패 : 벽을 한번만 뚫는건 잘 계산이 되었으나 뚫은 벽으로 최단시간 dist에 도달하여 값을 저장하는 문제 발생
// --> 기존의 조건문(dist의 크기)만으로는 판별이 불가능
// --> 2차원 배열을 하나 더 생성하여 벽을 뚫어서 거리가 저장된 것인지, 안뚫고 온것인지 여부 저장
*/

/* 문제 : 9466 - 텀 프로젝트
int board[100001];
bool vis[100001];
int ans[100001];
int n;
int sum;
stack<int> s;

void fs(int k) {
	s.push(k);
	while (true) {
		int ans2 = 0;
		int num = s.top();
		vis[num] = true;
		if (board[num] == num) {
			ans[num] = 1;
			break;
		}
		if (vis[board[num]]) {

			stack<int> stk;
			while (!s.empty()) {
				
				stk.push(s.top());
				if (ans[s.top()] == 1) { break; }
				if (s.top() == board[num]) {
					while (!stk.empty()) {
						ans[stk.top()] = 1;
						stk.pop();
					}
					break;
				}
				s.pop();
			}
			break;
		}
		s.push(board[num]);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		fill(vis, vis + m, false);
		fill(ans, ans + m, 0);
		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			board[i] = a - 1;
		}
		for (int i = 0; i < m; i++) {
			if (!vis[i]) { 
				fs(i);
			}
		}
		for (int i = 0; i < m; i++) {
			sum += ans[i];
		}
		cout << m - sum << "\n";
		sum = 0;
	}
}

// BFS문제인가? -> 모르겠음 각각의 학생은 다른 학생을 가르키는 구조 -> 스택이 생각남
// 시간을 최대로 줄이려면 방문여부(vis)를 이용하여 줄일수 있을듯
// BFS에서 스택을 사용하는 구조? -> DFS?
// 처음에는 vis만 이용하여 풀려고 하였으나, 실패
// --> 팀에 속하는 여부인 ans를 추가로 두어 해결(vis와 ans를 적절히 조합하여 조건 생성)
*/

/* 문제 2573 - 빙산
int board[302][302];
bool vis[302][302];
int n, m;
int year=0, chunk=0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;

void bfs(int w, int e) {
	vis[w][e] = true;
	Q.push({ w,e });
	while (!Q.empty()) {
		pair<int, int> p = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = p.X + dx[dir];
			int ny = p.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] == 0) continue;
			vis[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}

void oneyear() {
	int zero[303][303] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if ((nx >= 0 && nx < n && ny >= 0 && ny < m) && board[nx][ny] == 0) zero[i][j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			board[i][j] = max(0, board[i][j] - zero[i][j]);
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0);
		}
	}
	while (true)
	{
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, false);
		for (int w = 0; w < n; w++) {
			for (int e = 0; e < m; e++) {
				if (board[w][e] != 0 && !vis[w][e]) {
					chunk++;
					bfs(w, e);
				}
			}
		}
		if (chunk >= 2) {
			cout << year;
			break;
		}
		else {
			int sum = 0;
			chunk = 0;
			oneyear();
			year++;
			for (int w = 0; w < n; w++) {
				for (int e = 0; e < m; e++) {
					sum += board[w][e];
				}
			}
			if (sum == 0) {
				cout << 0;
				break;
			}
		}
	}
}

// 앞 두문제에 비해 비교적 쉬운문제
// 그림 나누기 문제에서 1년이 지날때마다 녹아내리는 함수만 추가하면 끝
*/

/* 문제 : 2146번 - 다리만들기 
int board[101][101];
bool vis[101][101];
int dist[101][101];
int n, num = 0;
int foot = 100000;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;

void bfs(int w, int e) {
	vis[w][e] = true;
	board[w][e] += num;
	Q.push({ w,e });
	while (!Q.empty()) {
		pair<int, int> p = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = p.X + dx[dir];
			int ny = p.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = true;
			board[nx][ny] += num;
			Q.push({ nx,ny });
		}
	}
}
void bfs2(int w, int e) {
	Q.push({w, e});
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == board[w][e]) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
			if (board[nx][ny] != board[w][e] && board[nx][ny] != 0) {
				foot = min(foot, dist[nx][ny]-1);
				while (!Q.empty()) {
					Q.pop();
				}
				break;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		fill(board[i], board[i] + n, 0);
		fill(vis[i], vis[i] + n, false);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	for (int w = 0; w < n; w++) {
		for (int e = 0; e < n; e++) {
			if (board[w][e] != 0 && !vis[w][e]) {
				num++;
				bfs(w, e);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) {
				for (int i = 0; i < n; i++) {
					fill(dist[i], dist[i] + n, -1);
				}
				dist[i][j] = 0;
				bfs2(i, j);
			}
		}
	}

	cout << foot;
}

// BFS두개의 유형이 결합된 문제(최단거리, 덩어러개수) 큰 아이디어 X
// 덩어리 나누기 -> 각 덩어리 끼리 같은 값을 할당 -> 각각의 타일에 대해 최단거리 BFS진행
// 시간 복잡도 N^4
*/

/* 문제: 13549 - 숨바꼭질3
int dist[100001];
int n, k;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int nx : {cur - 1, cur + 1}) {
			if (nx < 0 || nx > 100000) continue;
			if (dist[nx] >= 0 && dist[cur] + 1 > dist[nx]) continue;
			dist[nx] = dist[cur] + 1;
			q.push(nx);

		}
		int nx = cur * 2;
		if (nx < 0 || nx > 100000) continue;
		if (dist[nx] >= 0 && dist[cur] + 1 > dist[nx]) continue;
		dist[nx] = dist[cur];
		q.push(nx);

	}
	cout << dist[k];
}

// 기존 숨바꼭질 문제와 동일한 줄 알고 풀었으나 한번 틀림
// 곱하기 2로 이동하는게 시간소모가 0이기 때문인데,
// 이때문에 한번의 반복문 동안 큐에 채워진 요소들은 다른 소요시간을 가지고 있음(while문 조건 수정)
// 시간 소요가 다르기 때문에 방문요소로만은 그게 최단거리인지 알 수 없음(if문 조건 수정)
*/


// 문제 : 1600 - 말이 되고픈 원숭이
int dist[201][201];
int board[201][201];
int flag[201][201];
int I, w, h, ans = 0;
int dx[8] = { 1,2,1,2,-1,-2,-1,-2 };
int dy[8] = { 2,1,-2,-1,2,1,-2,-1 };
queue<pair<int, int>> Q;

int bfs(int k, int e) {
	dist[k][e] = 0;
	Q.push({ k,e });
	while (!Q.empty()) {
		pair<int, int> p = Q.front();
		Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = p.X + dx[dir];
			int ny = p.Y + dy[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[p.X][p.Y] + 1;
			Q.push({ nx,ny });
			cout << nx << "," << ny << "\n";
			if (dist[h-1][w-1] >= 0) {
				return dist[h-1][w-1];
			}
		}
	}
	return -1;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> I;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		fill(dist[i], dist[i] + w, -1);
	}
	cout << bfs(0, 0);
}

// 미완성 구현중
