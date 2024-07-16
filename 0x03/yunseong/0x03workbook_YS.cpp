//#include <bits/stdc++.h>
//using namespace std;
//
//void insert(int idx, int num, int arr[], int& len){
//    for(int i=len-1;i>=idx;i--)
//        arr[i+1] = arr[i];
//    arr[idx] = num;
//    len++;
//}
//
//void erase(int idx, int arr[], int& len){
//    for(int i=idx;i<len-1;i++) {
//        arr[i] = arr[i+1];
//    }
//    len--;
//}
//
//void printArr(int arr[], int& len){
//  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
//  cout << "\n\n";
//}
//
//void insert_test(){
//  cout << "***** insert_test *****\n";
//  int arr[10] = {10, 20, 30};
//  int len = 3;
//  insert(3, 40, arr, len); // 10 20 30 40
//  printArr(arr, len);
//  insert(1, 50, arr, len); // 10 50 20 30 40
//  printArr(arr, len);
//  insert(0, 15, arr, len); // 15 10 50 20 30 40
//  printArr(arr, len);
//}
//
//void erase_test(){
//  cout << "***** erase_test *****\n";
//  int arr[10] = {10, 50, 40, 30, 70, 20};
//  int len = 6;
//  erase(4, arr, len); // 10 50 40 30 20
//  printArr(arr, len);
//  erase(1, arr, len); // 10 40 30 20
//  printArr(arr, len);
//  erase(3, arr, len); // 10 40 30
//  printArr(arr, len);
//}
//
//int main(void) {
//  insert_test();
//  erase_test();
//}

// BOJ 2577 숫자의 개수
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//    int a, b, c;
//    int val;
//    int nums[10] = {0,};
//    cin >> a >> b >> c;
//
//    val = a * b * c;
//
//    while(val>0) {
//        nums[val % 10]++;
//        val /= 10;
//    }
//
//    for(int i=0;i<10;i++)
//        cout << nums[i] << '\n';
//
//    return 0;
//}

// BOJ 1475 방 번
//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//
//    char N[9];
//    int nums[10] = {0,};
//
//    scanf("%[^\n]s", N);
//
//    int i=0;
//    while(N[i] != '\0') {
//        nums[N[i] - '0']++;
//        i++;
//    }
//
//    int maxNum = 0;
//    for(i=0;i<10;i++) {
//        if(maxNum < nums[i] && (i != 6 && i != 9))
//            maxNum = nums[i];
//    }
//
//    int sixandnine = (nums[6] + nums[9]) / 2 + (nums[6] + nums[9]) % 2;
//    if(maxNum < sixandnine)
//        maxNum = sixandnine;
//
//    printf("%d", maxNum);
//
//    return 0;
//}

// BOJ 3273 두 수의 합
//#include <iostream>
//#include <stdlib.h>
//
//using namespace std;
//
//int main(void) {
//
//    int n, x;
//    int *nums = (int*)calloc(2000002, sizeof(int));
//    int sets = 0;
//    cin >> n;
//    int *a = (int*)malloc(sizeof(int)*n);
//
//    for(int i=0;i<n;i++) {
//        cin >> a[i];
//        nums[a[i]]++;
//    }
//
//    cin >> x;
//    for(int i=0;i<n;i++) {
//        if(x - a[i] > 0) {
//            if(nums[x - a[i]] && (x - a[i] != a[i])) {
//                nums[a[i]]--;
//                sets++;
//            }
//        }
//    }
//
//    cout << sets;
//
//    free(nums);
//    free(a);
//    return 0;
//}
//
//// 고려해야할 케이스 2개
///*
//1
//10
//20
//ans: 0
//wrong ans: 1
//*/
///*
//2
//10 5
//5
//ans: 0
//bounds 음수 체크
//*/
