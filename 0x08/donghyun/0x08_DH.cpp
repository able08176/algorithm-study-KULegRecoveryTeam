#include <bits/stdc++.h>
using namespace std;

/* 연습문제 : 1021
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, count = 0;
    cin >> n;
    while (n--) {
        stack<char> stk;
        string str;
        cin >> str;
        for (auto c : str) {
            if (!stk.empty() && stk.top() == c) stk.pop();
            else stk.push(c);
        }
        if (stk.empty()) count++;
    }
    cout << count;
}
*/
/* 응용문제 : 10799 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> stk;
    int count = 0, count2 = 0,score = 0;
    string str;
    cin >> str;
    for (auto c : str) {
        if (c == '(') {
            count++;
            stk.push(c);
        }
        else {
            if (stk.top() == '(') {
                score += --count;
            }
            else {
                count--;
                count2++;
            }
            stk.push(c);
        }
    }
    cout << score + count2;
}
*/
/* 응용문제 : 2504 */
int main()
{   
    bool isvalid = true;
    int mul = 1;
    int count = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> stk;
    string str;
    char ch2;
    cin >> str;
    for (char c : str) {
        if (c == '(') {
            stk.push(c);
            mul *= 2;
        }
        else if (c == '[') {
            stk.push(c);
            mul *= 3;
        }
        else if (c == ')') {
            if (stk.empty() || stk.top() != '(') {
                isvalid = false;
                break;
            }
            stk.pop();
            if(ch2 == '(') count += mul;
            mul /= 2;
        }
        else {
            if (stk.empty() || stk.top() != '[') {
                isvalid = false;
                break;
            }
            stk.pop();
            if (ch2 == '[') count += mul;
            mul /= 3;
        }
        ch2 = c;
    }
    if (isvalid && stk.empty()) cout << count;
    else cout << 0;
}

// 1. 괄호를 시작할때 가중치를 미리 곱하여준다
// 2. 닫는괄호의 경우 앞에 위치한 문자가 같은 종류의 열리는 괄호일때만 총합에 더해준다(중복방지)
// 3. 괄호가 닫히면 가중치를 나누어 준다
