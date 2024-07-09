//
// Created by JAEYOUNG PARK on 2024-07-10.
//

#include <bits/stdc++.h>
using namespace std;

int func1_jaeyoung(int N){
    // 문제 1
    // N 이하의 자연수 중에서 3의 배수이거나 5의 배수인 수를 모두 합한 값을 반환하는 함수 func1(int N)을 작성하라.
    // N은 10만 이하의 자연수이다.

    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        if ((i % 3 == 0) || (i % 5 == 0))
            sum += i;
    }
    return sum;
    // 시간복잡도: O(N)
}

int func2_jaeyoung(int arr[], int N){
    // 문제 2
    // 주어진 길이 N의 int 배열 arr에서
    // 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을,
    // 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
    // arr의 각 수는 0 이상 100 이하이고 N은 1000 이하이다.

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] + arr[j] == 100)
                return 1;
        }
    }
    return 0;
    // 시간복잡도: O(N^2)
}

int func3_jaeyoung(int N){
    // 문제 3
    // N이 제곱수이면 1을 반환하고 제곱수가 아니면 0을 반환하는
    // 함수 func3(int N)을 작성하라. N은 10억 이하의 자연수이다.

    for (int i = 1; i * i <= N; ++i) {
        if (i * i == N)
            return 1;
    }
    return 0;
    // 시간복잡도: O(sqrt(N))
}

int func4_jaeyoung(int N){
    // 문제 4
    // N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int N)을 작성하라.
    // N은 10억 이하의 자연수이다.

    int temp;
    for (int i = 1; i <= N; i*=2) {
        temp = i;
    }
    return temp;
    // 시간복잡도: O(log N)
}

int func1_yunseong(int N){
    return -1;
}

int func2_yunseong(int arr[], int N){
    return -1;
}

int func3_yunseong(int N){
    return -1;
}

int func4_yunseong(int N){
    return -1;
}

void test1(){
    cout << "****** func1 test ******\n";
    int n[3] = {16, 34567, 27639};
    int ans[3] = {60, 278812814, 178254968};
    for(int i = 0; i < 3; i++){
        int result = func1_jaeyoung(n[i]);
        cout << "TC #" << i << '\n';
        cout << "expected : " << ans[i] << " result : " << result;
        if(ans[i] == result) cout << " ... Correct!\n";
        else cout << " ... Wrong!\n";
    }
    cout << "*************************\n\n";
}

void test2(){
    cout << "****** func2 test ******\n";
    int arr[3][4] = {{1,52,48}, {50,42}, {4,13,63,87}};
    int n[3] = {3, 2, 4};
    int ans[3] = {1, 0, 1};
    for(int i = 0; i < 3; i++){
        int result = func2_jaeyoung(arr[i], n[i]);
        cout << "TC #" << i << '\n';
        cout << "expected : " << ans[i] << " result : " << result;
        if(ans[i] == result) cout << " ... Correct!\n";
        else cout << " ... Wrong!\n";
    }
    cout << "*************************\n\n";
}

void test3(){
    cout << "****** func3 test ******\n";
    int n[3] = {9, 693953651, 756580036};
    int ans[3] = {1, 0, 1};
    for(int i = 0; i < 3; i++){
        int result = func3_jaeyoung(n[i]);
        cout << "TC #" << i << '\n';
        cout << "expected : " << ans[i] << " result : " << result;
        if(ans[i] == result) cout << " ... Correct!\n";
        else cout << " ... Wrong!\n";
    }
    cout << "*************************\n\n";
}

void test4(){
    cout << "****** func4 test ******\n";
    int n[3] = {5, 97615282, 1024};
    int ans[3] = {4, 67108864, 1024};
    for(int i = 0; i < 3; i++){
        int result = func4_jaeyoung(n[i]);
        cout << "TC #" << i << '\n';
        cout << "expected : " << ans[i] << " result : " << result;
        if(ans[i] == result) cout << " ... Correct!\n";
        else cout << " ... Wrong!\n";
    }
    cout << "*************************\n\n";
}

int main(void){
    test1();
    test2();
    test3();
    test4();
}