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

    // BOJ 2753
    // int y;
    // cin >> y;
    // if (((y % 4 == 0) && !(y % 100 == 0)) || (y % 400 == 0))
    //     cout << "1";
    // else cout << "0";

    // BOJ 2480
    // int a, b, c;
    // cin >> a >> b >> c;
    // if (a == b && b == c) {
    //     cout << 10000 + a * 1000;
    // } else if (a != b && b == c) {
    //     cout << 1000 + b * 100;
    // } else if (b != a && a == c) {
    //     cout << 1000 + a * 100;
    // } else if (c != a && a == b) {
    //     cout << 1000 + a * 100;
    // } else if (a != b && b != c && c != a) {
    //     cout << 100 * max({a, b, c});
    // }

    // BOJ 2490
    // int n[3][4] = {};
    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 4; ++j) {
    //         cin >> n[i][j];
    //     }
    // }
    // int cnt = 0;
    // for (int i = 0; i < 3; ++i) {
    //     cnt = 0;
    //     for (int j = 0; j < 4; ++j) {
    //         if (n[i][j] == 1)
    //             cnt++;
    //     }
    //     switch (cnt) {
    //         case 0:
    //             cout << "D\n";
    //             break;
    //         case 1:
    //             cout << "C\n";
    //             break;
    //         case 2:
    //             cout << "B\n";
    //             break;
    //         case 3:
    //             cout << "A\n";
    //             break;
    //         case 4:
    //             cout << "E\n";
    //             break;
    //     }
    // }

    // BOJ 2576
    // int nums[7];
    // int n;
    // int sum = 0;
    // fill(nums, nums + 7, 100);
    // for (int i = 0; i < 7; ++i) {
    //     cin >> n;
    //     if (n % 2 == 1) {
    //         sum += n;
    //         nums[i] = n;
    //     }
    // }
    // if (sum == 0) {
    //     cout << -1;
    //     return 0;
    // }
    // cout << sum << "\n";
    // cout << *min_element(nums, nums + 7);

    // BOJ 2587
    // int arr[5] = {};
    // int sum = 0;
    // for (int i = 0; i < 5; ++i) {
    //     cin >> arr[i];
    //     sum += arr[i];
    // }
    // cout << sum / 5 << "\n";
    // sort(arr, arr + 5);
    // cout << arr[2];

    // BOJ 1008
    // double a, b;
    // cin >> a >> b;
    // printf("%.13lf", a / b);

    // BOJ 2309
    // int hs[9] = {};
    // int sum = 0;
    // for (int i = 0; i < 9; ++i) {
    //     cin >> hs[i];
    //     sum += hs[i];
    // }
    // sort(hs, hs + 9);
    // for (int i = 0; i < 8; ++i) {
    //     for (int j = i + 1; j < 9; ++j) {
    //         if ((sum - hs[i] - hs[j]) == 100) {
    //             for (int k = 0; k < 9; ++k) {
    //                 if (k == i || k == j)
    //                     continue;
    //                 cout << hs[k] << "\n";
    //             }
    //             return 0;
    //         }
    //     }
    // }

    // BOJ 10093
    // long a, b;
    // cin >> a >> b;
    // long max = std::max(a, b);
    // long min = std::min(a, b);
    // long num = max - min - 1;
    // if (max == min)
    //     num = 0;
    // cout << num << "\n";
    // for (int i = 1; i < num + 1; ++i) {
    //     cout << min + i << " ";
    // }

    // BOJ 1267
    // int n;
    // int sum_y = 0;
    // int sum_m = 0;
    // int t;
    // cin >> n;
    // for (int i = 0; i < n; ++i) {
    //     cin >> t;
    //     sum_y += 10 * (1 + t / 30);
    //     sum_m += 15 * (1 + t / 60);
    // }
    // if (sum_y<sum_m) {
    //     cout << "Y " << sum_y;
    // } else if (sum_y > sum_m) {
    //     cout << "M " << sum_m;
    // } else {
    //     cout << "Y M " << sum_m;
    // }

    // BOJ 10804
    // int cards[20] = {};
    // for (int i = 0; i < 20; ++i) {
    //     cards[i] = i + 1;
    // }
    // int arr[10][2] = {};
    // for (int i = 0; i < 10; ++i) {
    //     for (int j = 0; j < 2; ++j) {
    //         cin >> arr[i][j];
    //         arr[i][j] -= 1;
    //     }
    // }
    // for (int i = 0; i < 10; ++i) {
    //     int n = arr[i][1] - arr[i][0] + 1;
    //     for (int j = 0; j < n / 2; ++j) {
    //         swap(cards[arr[i][0] + j], cards[arr[i][1] - j]);
    //     }
    // }
    // for (int i = 0; i < 20; ++i) {
    //     cout << cards[i] << " ";
    // }

    // BOJ 15552
    // int n;
    // cin >> n;
    // int a, b;
    // for (int i = 0; i < n; ++i) {
    //     cin >> a >> b;
    //     cout << a + b << "\n";
    // }

    // BOJ 2442
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n - i - 1; ++j) {
    //         cout << " ";
    //     }
    //     for (int j = 0; j < 2 * i + 1; ++j) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // BOJ 2562
    int nums[9] = {};
    for (int i = 0; i < 9; ++i) {
        cin >> nums[i];
    }
    cout << *max_element(nums, nums + 9) << "\n";
    cout << max_element(nums, nums + 9) - nums + 1;
}
