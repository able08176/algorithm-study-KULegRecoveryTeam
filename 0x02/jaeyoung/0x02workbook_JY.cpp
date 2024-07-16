//
// Created by Admin on 2024-07-16.
//
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // BOJ 1000
    // int a, b;
    // cin >> a >> b;
    // cout << (a + b);

    // BOJ 2557
    // cout << "Hello World!";

    // BOJ 15171
    // cout << "\\    \/\\" << "\n";
    // cout << " )  ( \')" << "\n";
    // cout << "(  /  )" << "\n";
    // cout << " \\(__)|" << "\n";

    // BOJ 10869
    // int a, b;
    // cin >> a >> b;
    // cout << a + b << "\n";
    // cout << a - b << "\n";
    // cout << a * b << "\n";
    // cout << a / b << "\n";
    // cout << a % b << "\n";

    // BOJ 9498
    // int n;
    // cin >> n;
    // if (n >= 90 && n <= 100)
    //     cout << "A";
    // else if (n >= 80 && n <= 89)
    //     cout << "B";
    // else if (n >= 70 && n <= 79)
    //     cout << "C";
    // else if (n >= 60 && n <= 69)
    //     cout << "D";
    // else
    //     cout << "F";

    // BOJ 2752
    // int a, b, c;
    // cin >> a >> b >> c;
    // int d, e, f;
    // d = max({a, b, c});
    // f = min({a, b, c});
    // e = a + b + c - d - f;
    // cout << f << " " << e << " " << d;

    //BOJ 2753
    int y;
    cin >> y;
    if (((y % 4 == 0) && !(y % 100 == 0)) || (y % 400 == 0))
        cout << "1";
    else cout << "0";
}
