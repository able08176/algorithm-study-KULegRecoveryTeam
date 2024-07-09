//
// Created by JAEYOUNG PARK on 2024-07-10.
//

#include <bits/stdc++.h>
using namespace std;

int func1_jaeyoung(int N){
    return -1;
}

int func2_jaeyoung(int arr[], int N){
    return -1;
}

int func3_jaeyoung(int N){
    return -1;
}

int func4_jaeyoung(int N){
    return -1;
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