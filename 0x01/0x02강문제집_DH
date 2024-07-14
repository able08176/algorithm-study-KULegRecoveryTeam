#include <bits/stdc++.h>
using namespace std;

/* 문제 : 2577
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, m, arr[10];
	fill(arr, arr + 10, 0);
	cin >> a >> b >> c;
	m = a * b * c;
	while (m != 0) {
		arr[m % 10]++;
		m /= 10;
	}
	for (int i = 0; i < 10; i++) cout << arr[i] << "\n";
}
*/

/* 문제 : 1475
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, arr[9], max = 0;
	fill(arr, arr + 9, 0);
	cin >> a;
	while (a != 0) {
		if (a % 10 == 9) arr[6]++;
		else arr[a % 10]++;
		a /= 10;
	}
	if (arr[6] % 2 == 0) arr[6] /= 2;
	else arr[6] = arr[6] / 2 + 1;

	for (int i = 0; i < 9; i++) {
		if (arr[i] > max) max = arr[i];
	}
	cout << max;
}
*/

/* 문제 : 3273
int arr[2000001] = {};
int arr2[100000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, count = 0;
	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> arr2[k];
		arr[arr2[k]]++;
	}
	cin >> x;
	for (int k = 0; k < n; k++) if (arr[arr2[k]] == 1 && arr[x - arr2[k]] == 1) count++;
	cout << count / 2;
}
*/
