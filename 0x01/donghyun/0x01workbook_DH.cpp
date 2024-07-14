#include <bits/stdc++.h>
using namespace std;
/* 문제 : 1000
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << a + b;
	return 0;
}
*/

/* 문제 : 2557
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << "Hello World!";
	return 0;
}
*/

/* 문제 : 10171
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << "\\    /\\\n";
	cout << " )  ( \')\n";
	cout << "(  /  )\n";
	cout << " \\(__)|\n";
	return 0;
}
*/

/* 문제 : 10869
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << a + b << "\n";
	cout << a - b << "\n";
	cout << a * b << "\n";
	cout << a / b << "\n";
	cout << a % b << "\n";
	return 0;
}
*/

/* 문제 : 9498
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int score;
	cin >> score;
	switch (score / 10) {
	case 10:
	case 9:
		cout << 'A';
		break;
	case 8:
		cout << 'B';
		break;
	case 7:
		cout << 'C';
		break;
	case 6:
		cout << 'D';
		break;
	default:
		cout << 'F';
	}
	return 0;
}
*/

/* 문제 : 2752
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[3];
	for (int n = 0; n < 3; n++) cin >> arr[n];
	for (int j = 0; j < 3; j++) {
		for (int i = j+1; i < 3; i++) {
			if (arr[j] > arr[i])
			{
				int num = arr[j];
				arr[j] = arr[i];
				arr[i] = num;
			}		
		}
		cout << arr[j] << " ";
	}

	return 0;
}
*/

/* 문제 : 2753
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int year;
	cin >> year;
	if (year % 4 == 0) {
		if (year % 100 != 0 || year % 400 == 0) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
*/

/* 문제 : 2480
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c && c == a) cout << 10000 + a * 1000;
	else if (a == b || b == c || c == a) cout << 1000 + ((a == b) ? a : c) * 100;
	else cout << max({ a,b,c }) * 100;
	return 0;
}
*/

/* 문제 : 2490
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str = "";
	int a, b, c, d;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b >> c >> d;
		if (a + b + c + d != 4)	str += 'D' - a - b - c - d;
		else str += 'E';
	}
	for (int i = 0; i < 3; i++) {
		cout << str[i] << "\n";
	}
	return 0;
}
*/

/* 문제 : 2576
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num, sum = 0, min = 99, count = 0;
	for (int i = 0; i < 7; i++) {
		cin >> num;
		if (num % 2 == 1) {
			sum += num;
			count++;
			if (num < min) min = num;
		}
	}
	if (count == 0) cout << -1;
	else cout << sum << "\n" << min;
}
*/

/* 문제 : 2587
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sort(num, num + 5);
	cout << sum / 5 << "\n" << num[2];
}
*/

/* 문제 : 2587 : 일곱난쟁이 문제
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) if (sum - arr[i] - arr[j] == 100) arr[i] = arr[j] = 0;
	}
	sort(arr, arr + 9);
	for (int i = 2; i < 9; i++) cout << arr[i] << "\n";
}
*/

/* 문제 : 10093
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;
	if (a > b) {
		cout << a - b - 1 << "\n";
		while (a-1 > b) {
			b++;
			cout << b << " ";
		}
	}
	else if(a < b) {
		cout << b - a - 1 << "\n";
		while (b-1 > a) {
			a++;
			cout << a << " ";
		}
	}
	else {
		cout << 0;
	}
}
*/

/* 문제 : 1267
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m = 0, y = 0, n, num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> n;
		y += (n / 30) * 10 + 10;
		m += (n / 60) * 15 + 15;
	}
	if (m > y) cout << "Y " << y;
	else if (m < y) cout << "M " << m;
	else cout << "Y M " << m;
}
*/

/* 문제 : 10804
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, arr[21];
	for (int i = 1; i < 21; i++) arr[i] = i;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		for (int k = a; k < (a + b) / 2; k++) swap(arr[k], arr[b + a - k]);
	}
	for (int i = 1; i < 21; i++) cout << arr[i] << " ";
}
*/

/* 문제 : 15552
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[i] = a + b;
	}
	for (int i = 0; i < n; i++) cout << arr[i] << "\n";
	delete[] arr;
}
*/

/* 문제 : 2562
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num, max = 0, count = 1, maxcount;
	for (int i = 0; i < 9; i++) {
		cin >> num;
		if (num > max) {
			max = num;
			maxcount = count;
		}
		count++;
	}
	cout << max << "\n" << maxcount;
}
*/

// 별문제는 안할래 너무 귀찮아
