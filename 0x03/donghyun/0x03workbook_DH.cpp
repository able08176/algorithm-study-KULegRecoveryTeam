#include <bits/stdc++.h>
using namespace std;

/* 문제 : 5397
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a;
	string str;
	cin >> a;
	for (int n = 0; n < a; n++) {
		cin >> str;
		list<char> L = {};
		auto cursor = L.begin();
		for (auto i : str) {
			if (i == '<') {
				if (cursor != L.begin()) cursor--;
			}
			else if (i == '>') {
				if (cursor != L.end()) cursor++;
			}
			else if (i == '-') {
				if (cursor != L.begin()) cursor = L.erase(--cursor);
			}
			else L.insert(cursor, i);
		}
		for (auto c : L) cout << c;
		cout << "\n";

	}
}
*/
// 문제 : 1158 요세푸스 문제
// 런타임오류 : 왜뜨는건지 모르겠음
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	list<int> L = {};
	cin >> n >> k;

	for (int i = 1; i < n + 1; i++) L.push_back(i);

	auto cursor = L.begin();
	cout << "<";
	for (int i = 0; i < k; i++) cursor++;
	cout << *--cursor << ", ";
	cursor = L.erase(cursor);
	cursor--;


	for (int i = 1; i < n + 1; i++) {
		for (int m = 0; m < k; m++) {
			if (cursor == L.end()) cursor = L.begin();
			cursor++;
		}
		if (cursor == L.end()) cursor = L.begin();

		cout << *cursor;
		cursor = L.erase(cursor);

		if (L.size() == 0) break;
		cout << ", ";
		if (cursor == L.begin()) cursor = L.end();
		cursor--;
	}
	cout << ">";
}
