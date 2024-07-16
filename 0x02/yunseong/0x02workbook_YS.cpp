//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int N, X, num;
//    int a[10005], pa = 0;
//    cin >> N >> X;
//    for(int i=0;i<N;i++) {
//        cin >> num;
//        if(num < X)
//            a[pa++] = num;
//    }
//
//    for(int i=0;i<pa;i++) {
//        cout << a[i] << ' ';
//    }
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int A, B;
//    cin >> A >> B;
//    cout << A+B;
//
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//    string s = "Hello World!";
//    cout << s;
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//    string cat = "\\    /\\\n )  ( \')\n(  /  )\n \\(__)|";
//    cout << cat;
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int grade;
//    cin >> grade;
//
//    if(grade >= 90)
//        cout << "A";
//    else if(grade >= 80)
//        cout << "B";
//    else if(grade >= 70)
//        cout << "C";
//    else if(grade >= 60)
//        cout << "D";
//    else
//        cout << "F";
//
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//void sw(int& a, int& b) {
//    int tmp = a;a = b;b = tmp;
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int a[3];
//
//    for(int i=0;i<3;i++)
//        cin >> a[i];
//
//    int s;
//    for(int i=0;i<3;i++) {
//        s = i;
//        for(int j=i+1;j<3;j++) {
//            if(a[s] > a[j])
//                s = j;
//        }
//
//        if(i!=s) {
//            sw(a[s], a[i]);
//        }
//    }
//
//    for(int i=0;i<3;i++)
//        cout << a[i] << ' ';
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void){
//
//    int year;
//    cin >> year;
//
//    if(year % 4 == 0) {
//        if(year % 400 == 0)
//            cout << "1";
//        else if(year % 100 == 0)
//            cout << "0";
//        else
//            cout << "1";
//    } else {
//        cout << "0";
//    }
//
//    return 0;
//}

/*
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    vector<int> a(7);
    int eye;
    for(int i=0;i<3;i++) {
        cin >> eye;
        a[eye]++;
    }

    int maxEye = 0;
    for(int i=1;i<7;i++) {
        if(a[i] == 3) {
            cout << 10000+i*1000;
            break;
        }
        else if(a[i] == 2) {
            cout << 1000+i*100;
            break;
        }
        else if(a[i] == 1) {
            maxEye = i;
        }

        if(i==6)
            cout << maxEye*100;
    }


    return 0;
}
*/

/*
#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int t=0;t<3;t++) {
        int a[2] = {0,};
        int wood;

        for(int i=0;i<4;i++) {
            cin >> wood;
            a[wood]++;
        }

        switch(a[1]) {

        case 0:
            cout << "D\n";
            break;
        case 1:
            cout << "C\n";
            break;
        case 2:
            cout << "B\n";
            break;
        case 3:
            cout << "A\n";
            break;
        case 4:
            cout << "E\n";
        }
    }

    return 0;
}
*/

/*
#include <iostream>

using namespace std;

int main(void){
    int a[7];
    int oddSum = 0;
    int minOdd = 2147483645;

    for(int i=0;i<7;i++) {
        cin >> a[i];
        if(a[i] % 2 == 1) {
            oddSum += a[i];
            if(a[i] < minOdd)
                minOdd = a[i];
        }
    }

    if(oddSum == 0)
        cout << -1;
    else
        cout << oddSum << '\n' << minOdd;

    return 0;
}
*/

/*
#include <iostream>

using namespace std;

void sw(int& a, int& b) {
    int tmp = a;a = b;b = tmp;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[5];
    int sum = 0, avg, mid;

    for(int i=0;i<5;i++) {
        cin >> a[i];
        sum += a[i];
    }

    avg = sum/5;

    int tmp;
    int pos;
    for(int i=1;i<5;i++) {
        tmp = a[i];
        pos = i-1;
        while(pos >= 0) {
            if(a[pos] > tmp) {
                sw(a[pos], a[pos+1]);
                pos--;
            } else break;
        }

        a[pos+1] = tmp;
    }
    mid = a[2];

    cout << avg << "\n" << mid;

    return 0;
}
*/

//#include <iostream>
//
//using namespace std;
//
//void sw(int& a, int& b) {
//    int tmp=a;a=b;b=tmp;
//}
//
//int main(void) {
//
//    int h[9];
//    int hSum = 0;
//    for(int i=0;i<9;i++) {
//        cin >> h[i];
//        hSum+=h[i];
//    }
//
//    // insertion sort
//    int pos;
//    int tmp;
//    for(int i=1;i<9;i++) {
//        pos = i-1;
//        tmp = h[i];
//        while(pos>=0) {
//            if(h[pos] > tmp) {
//                sw(h[pos], h[pos+1]);
//                pos--;
//            } else break;
//        }
//        h[pos+1]=tmp;
//    }
//
//    int no1, no2;
//    for(int i=0;i<8;i++) {
//        for(int j=i+1;j<9;j++) {
//            if(hSum - h[i] - h[j] == 100) {
//                no1 = h[i];
//                no2 = h[j];
//                break;
//            }
//        }
//    }
//
//    for(int i=0;i<9;i++) {
//        if(h[i] != no1 && h[i] != no2)
//            cout << h[i] << "\n";
//    }
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    long long A, B;
//    long long tmp;
//    long long gap;
//
//    cin >> A >> B;
//
//    if(A > B) {
//        tmp = A;
//        A = B;
//        B = tmp;
//    }
//
//    if(A == B)
//        gap = 0;
//    else
//        gap = B - A - 1;
//
//    cout << gap << "\n";
//
//    A++;
//    while(A < B) {
//        cout << A << ' ';
//        A++;
//    }
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    int call;
//    int Y = 0, M = 0;
//
//    cin >> N;
//    for(int i=0;i<N;i++) {
//        cin >> call;
//        Y += (call / 30 + 1) * 10;
//        M += (call / 60 + 1) * 15;
//    }
//
//    if(Y <= M)
//        cout << "Y ";
//
//    if(M <= Y)
//        cout << "M " << M;
//    else
//        cout << Y;
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//void sw(int* p, int* q) {
//    int tmp = *p;*p = *q;*q = tmp;
//}
//
//void reverse_card(int c[], int a, int b) {
//    int t = 0;
//    t = (b - a + 1)/2;
//
//    int i = 0;
//    while(i<t) {
//        sw(&c[a+i], &c[b-i]);
//        i++;
//    }
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int a, b;
//    int cards[21] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
//    for(int i=0;i<10;i++) {
//        cin >> a >> b;
//        reverse_card(cards, a, b);
//    }
//
//    for(int i=1;i<21;i++)
//        cout << cards[i] << ' ';
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    int n;
//    cin >> n;
//
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<i;j++)
//            cout << ' ';
//        for(int k=n;k>i;k--)
//            cout << '*';
//        cout << "\n";
//    }
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    int n;
//    cin >> n;
//
//    for(int i=0;i<n-1;i++) {
//        for(int j=0;j<n-i-1;j++)
//            cout << ' ';
//        for(int k=0;k<i+1;k++)
//            cout << '*';
//        for(int r=1;r<i+1;r++)
//            cout << '*';
//
//        cout << "\n";
//    }
//
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<i;j++)
//            cout << ' ';
//        for(int k=n;k>i;k--)
//            cout << '*';
//        for(int r=n;r>i+1;r--)
//            cout << '*';
//
//        cout << "\n";
//    }
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//    int n;
//    cin >> n;
//
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<i+1;j++)
//            cout << '*';
//        for(int k=n-1;k>i;k--)
//            cout << ' ';
//
//        for(int k=n-1;k>i;k--)
//            cout << ' ';
//        for(int j=0;j<i+1;j++)
//            cout << '*';
//
//        cout << "\n";
//    }
//
//    for(int i=0;i<n;i++) {
//        for(int k=n-1;k>i;k--)
//            cout << '*';
//        for(int j=0;j<i+1;j++)
//            cout << ' ';
//
//        for(int j=0;j<i+1;j++)
//            cout << ' ';
//        for(int k=n-1;k>i;k--)
//            cout << '*';
//
//        cout << "\n";
//    }
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//    int n;
//    cin >> n;
//
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<i;j++)
//            cout << ' ';
//        for(int k=n;k>i;k--)
//            cout << '*';
//        for(int r=n-1;r>i;r--)
//            cout << '*';
//
//        cout << "\n";
//    }
//
//    for(int i=2;i<=n;i++) {
//        for(int j=n;j>i;j--)
//            cout << ' ';
//        for(int k=0;k<i;k++)
//            cout << '*';
//        for(int r=1;r<i;r++)
//            cout << '*';
//
//        cout << "\n";
//    }
//
//    return 0;
//}
