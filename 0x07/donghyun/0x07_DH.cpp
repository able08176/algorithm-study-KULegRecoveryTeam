#include <bits/stdc++.h>
using namespace std;

/* 연습문제 : 1021 - 덱을 사용한 풀이
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, count = 0;
    cin >> a >> b;
    deque<int> DQ;
    for (int i = 1; i < a + 1; i++) DQ.push_back(i);
    while (b--) {
        int num;
        cin >> num;
        if (num == DQ.front()) DQ.pop_front();
        else {
            int count2 = 0;
            while (num != DQ.front()) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
                count2++;
            }
            count += (count2 < DQ.size() - count2) ? count2 : DQ.size() - count2;
            DQ.pop_front();
        }
    }
    cout << count;
}
*/

// 맨앞에 원소 제거, 맨뒤 원소 추가가 들어가므로 큐를 써도 되지 않을까?

/* 연습문제 : 1021 - 큐를 사용한 풀이 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, count = 0;
    cin >> a >> b;
    queue<int> DQ;
    for (int i = 1; i < a + 1; i++) DQ.push(i);
    while (b--) {
        int num;
        cin >> num;
        if (num == DQ.front()) DQ.pop();
        else {
            int count2 = 0;
            while (num != DQ.front()) {
                DQ.push(DQ.front());
                DQ.pop();
                count2++;
            }
            count += (count2 < DQ.size() - count2) ? count2 : DQ.size() - count2;
            DQ.pop();
        }
    }
    cout << count;
}
*/

/* 응용 문제 : 5430 */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int m;
        bool flag = true;
        bool flag2 = true;
        string str, arr;
        string str2 = "";
        deque<int> DQ;
        cin >> str >> m >> arr;
        if (m != 0) {
            for (int i = 0; i < arr.length(); i++) {
                if (arr[i] == '[' || arr[i] == ',' || arr[i] == ']') {
                    if (arr[i] != '[') DQ.push_back(stoi(str2));
                    str2 = "";
                    continue;
                }
                str2 += arr[i];
            }
        }
        for (char c : str) {
            if (c == 'R') {
                flag2 = !flag2;
            }
            else {
                if (DQ.size() == 0) { flag = false; break; }
                if (flag2 == true) DQ.pop_front();
                else DQ.pop_back();
            }
        }
        if (flag == true) {
            cout << "[";
            while(!DQ.empty()){
                if (flag2 == true) {
                    cout << DQ.front();
                    DQ.pop_front();
                }else {
                    cout << DQ.back();
                    DQ.pop_back();
                }
                if(!DQ.empty()) cout << ",";
            }
            cout << "]\n";
        }
        else cout << "error\n";
    }
}

// 5430번 이 tlqkffus 드디어 풀었네 뭐가 문제인지 몰라서 1시간 30분걸림ㅁ
// 하면서 겪었던 문제들
// 1. 시간 초과 : 덱을 뒤집는 과정에서 시간초과 발생 -> 플래그 변수를 세워두어 출력형식만 바꾸어준다
// 2. 입력 오류 : 입력할때 숫자가 두자리인 경우를 생각안함
// 3. 출력 오류 : 빈 배열일 경우 error가 아닌, []을 출력
