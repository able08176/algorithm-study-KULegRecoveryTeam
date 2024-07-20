#include <bits/stdc++.h>
using namespace std;

/* 연습문제 : 10828
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> stk;
    int a;
    cin >> a;
    while (a--) {
        string str;
        cin >> str;
        if (str == "push") {
            int b;
            cin >> b;
            stk.push(b);
        }
        else if (str == "top") {
            if (stk.empty()) cout << "-1\n";
            else cout << stk.top() << "\n";
        }
        else if (str == "size") {
            cout << stk.size() << "\n";
        }
        else if (str == "empty") {
            cout << (int)stk.empty() << "\n";
        }
        else if (str == "pop") {
            if (stk.empty()) cout << "-1\n";
            else {
                cout << stk.top() << "\n";
                stk.pop();
            }
        }
    }
}
*/
/* 기본문제 : 10773 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0;
    cin >> n;
    stack<int> stk;

    while (n--) {

        int a;
        cin >> a;

        if (a == 0) stk.pop();
        else stk.push(a);
    }

    while (!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    
    cout << sum;
}
*/

/* 응용문제 : 1874 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b = 1;
    string str = "";
    cin >> n;
    stack<int> stk;
    while (n--) {
        cin >> a;
        while (b < a + 1) {
            stk.push(b++);
            str += "+\n";
        }
        if (stk.top() > a) {
            cout << "NO";
            return 0;
        }
        stk.pop();
        str += "-\n";
    }
    cout << str;
}
*/
// 1. a가 입력됨
// 2. a가 스택의 top보다 큰 경우, stack에 1씩 더한값을 a와 같아질때까지 push한 후 pop
// 3. a가 스택의 top보다 같은 경우, stack의 top과 같다면 그대로 pop
// 4. a가 스택의 top보다 작은 경우, 불가능하므로 NO 출력
// 왜? 스택에는 숫자들이 무조건 오름차순으로 정렬되어있으므로 a를 pop하려면 top을 pop을 해줘야 하는데, 이러면 top을 출력할 수 없음 

/* 응용문제 : 2493 : 일단보류 스택으로 어케품 이거 */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
    }

}
