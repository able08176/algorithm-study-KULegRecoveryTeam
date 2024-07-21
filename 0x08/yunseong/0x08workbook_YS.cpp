// BOJ 4949 균형잡힌 세상
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int pu; // pointer of userInput
//    bool isYes = true;
//
//    while(true) {
//        string userInput;
//        getline(cin, userInput);
//
//        if(userInput[0] == '.')
//            break;
//
//        pu = 0;
//        isYes = true;
//        stack<char> S;
//
//        while(userInput[pu] != '.') {
//            if(userInput[pu] == '(' || userInput[pu] == '[')
//                S.push(userInput[pu]);
//            else if(userInput[pu] == ')') {
//                if(S.empty()) {
//                    isYes = false;
//                    break;
//                } else if(S.top() == '(') {
//                    S.pop();
//                } else {
//                    isYes = false;
//                    break;
//                }
//            } else if(userInput[pu] == ']') {
//                if(S.empty()) {
//                    isYes = false;
//                    break;
//                } else if(S.top() == '[') {
//                    S.pop();
//                } else {
//                    isYes = false;
//                    break;
//                }
//            }
//
//            pu++;
//        }
//
//        if(!S.empty())
//            isYes = false;
//
//        if(isYes) {
//            cout << "yes\n";
//        } else {
//            cout << "no\n";
//        }
//    }
//
//    return 0;
//}

// BOJ 10799 쇠막대기
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    string input;
//    stack<char> S;
//    int pi = 0; // pointer of input
//    int cnt = 0; // 조각의 수
//
//    cin >> input;
//
//    while(input[pi] != '\0') {
//        if(input[pi] == '(') {
//            S.push('(');
//        }
//        else if(input[pi] == ')'){
//            if(input[pi-1] == '(') { // it's a lazer
//                cnt += S.size() - 1;
//                S.pop();
//            }
//            else if(input[pi-1] == ')') {
//                cnt++;
//                S.pop();
//            }
//        }
//
//        pi++;
//    }
//
//    cout << cnt;
//
//    return 0;
//}

/* 쇠막대기 <풀이노트>

')'를 만나면 '('를 하나 팝 한다.
(= ')'는 절대 스택에 들어가지 않는다)

팝 할때의 경우는 2가지

1. 문자열에서 이전 문자가 '(' 였다
=> 이건 레이저였다는 뜻. 스택에 남아있는 '('개수 -1 을 cnt에 더해준다. '('개수는 그냥 스택의 size이다.
(-1 하는 이유는 레이저의 '(' 제외 시키기 위함)

2. 문자열에서 이전 문자가 ')' 였다.
=> 쇠막대기 하나 끝났다는 뜻. 그냥 '('하나 팝 해준다.
+) 구현하다보니 여기서 cnt++을 해줘야 함을 알았다. 어떤 쇠막대기든간에 반드시 한번은 잘린다는 사실 때문에, 쇠막대기의 끝( ')'을 팝하는 것 )에서 해당 쇠막대기 가장 오른쪽 조각을 더해줘야 한다.

문자열 끝에 도달하면 종료.

cnt의 합은 조각의 수이다. cnt를 출력하면 된다.

*/

// BOJ 2504 괄호의 값
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    string input;
//    int pi = 0; // pointer of input
//    int sum = 0;
//    int tmp;
//    bool isValid = true;
//    stack<char> C; // for char '(' or ')'....
//    stack<int> V; // for value
//
//    cin >> input;
//
//    while(input[pi] != '\0') {
//
//        if(input[pi] == '(' || input[pi] == '[') {
//            C.push(input[pi]);
//            V.push(0);
//        }
//
//        if(input[pi] == ')') {
//            if(C.empty() || C.top() != '(') {
//                isValid = false;
//                break;
//            }
//
//            if(V.top() == 0)
//                tmp = 2;
//            else {
//                tmp = 2*V.top();
//            }
//
//            V.pop();
//            C.pop();
//
//            if(V.empty()) {
//                sum += tmp;
//            }
//            else {
//                V.top() += tmp;
//            }
//        }
//
//        if(input[pi] == ']') {
//            if(C.empty() || C.top() != '[') {
//                isValid = false;
//                break;
//            }
//
//            if(V.top() == 0)
//                tmp = 3;
//            else {
//                tmp = 3*V.top();
//            }
//
//            V.pop();
//            C.pop();
//
//            if(V.empty()) {
//                sum += tmp;
//            }
//            else {
//                V.top() += tmp;
//            }
//
//        }
//
//        pi++;
//    }
//
//    if(!C.empty())
//        isValid = false;
//
//    if(isValid)
//        cout << sum;
//    else
//        cout << 0;
//
//    return 0;
//}

/* 괄호의 합 <풀이노트>

sum = 0

스택 사이즈 0 될때마다 sum에 합

스택 2개 사용

(

0

((

0 0

(() -> (

2

([

2 0

([[

2 0 0

([[] -> ([

2 3

([(

2 3 0

([() -> ([

2 3+2

([] -> (

2 3*3

() ->

2+3*3

여는 괄호마다 스택이 늘어난다
닫히는 괄호가 나오면 해당 스택의 탑을 꺼내고 팝한뒤, 새로운 탑에 더한다.

이때 새로운 탑에 가면서 원래 내 값이 0이었다면 해당하는 값(2or3) 만 주고,
0이 아니었다면 그 수에 해당하는 값을 곱해서 간다.

만약 넣을 새로운 탑이 없으면(내가 마지막 top이었으면) sum에 더한다.

문자열 끝 만나면 종료! sum 출력

*/

// BOJ 3986 좋은 단어
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    int cnt = 0;
//    int pw = 0; // pointer of words
//
//    cin >> N;
//
//    while(N > 0) {
//        string words;
//        pw = 0;
//
//        cin >> words;
//
//        stack<char> W;
//
//        W.push(words[pw++]);
//
//        while(words[pw] != '\0') {
//            if(!W.empty() && words[pw] == W.top()) {
//                W.pop();
//            } else {
//                W.push(words[pw]);
//            }
//
//            pw++;
//        }
//
//        if(W.empty())
//            cnt++;
//
//        N--;
//    }
//
//    cout << cnt;
//
//    return 0;
//}
