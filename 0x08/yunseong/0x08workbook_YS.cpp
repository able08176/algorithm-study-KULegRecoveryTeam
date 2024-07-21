// BOJ 4949 �������� ����
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

// BOJ 10799 �踷���
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
//    int cnt = 0; // ������ ��
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

/* �踷��� <Ǯ�̳�Ʈ>

')'�� ������ '('�� �ϳ� �� �Ѵ�.
(= ')'�� ���� ���ÿ� ���� �ʴ´�)

�� �Ҷ��� ���� 2����

1. ���ڿ����� ���� ���ڰ� '(' ����
=> �̰� ���������ٴ� ��. ���ÿ� �����ִ� '('���� -1 �� cnt�� �����ش�. '('������ �׳� ������ size�̴�.
(-1 �ϴ� ������ �������� '(' ���� ��Ű�� ����)

2. ���ڿ����� ���� ���ڰ� ')' ����.
=> �踷��� �ϳ� �����ٴ� ��. �׳� '('�ϳ� �� ���ش�.
+) �����ϴٺ��� ���⼭ cnt++�� ����� ���� �˾Ҵ�. � �踷���簣�� �ݵ�� �ѹ��� �߸��ٴ� ��� ������, �踷����� ��( ')'�� ���ϴ� �� )���� �ش� �踷��� ���� ������ ������ ������� �Ѵ�.

���ڿ� ���� �����ϸ� ����.

cnt�� ���� ������ ���̴�. cnt�� ����ϸ� �ȴ�.

*/

// BOJ 2504 ��ȣ�� ��
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

/* ��ȣ�� �� <Ǯ�̳�Ʈ>

sum = 0

���� ������ 0 �ɶ����� sum�� ��

���� 2�� ���

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

���� ��ȣ���� ������ �þ��
������ ��ȣ�� ������ �ش� ������ ž�� ������ ���ѵ�, ���ο� ž�� ���Ѵ�.

�̶� ���ο� ž�� ���鼭 ���� �� ���� 0�̾��ٸ� �ش��ϴ� ��(2or3) �� �ְ�,
0�� �ƴϾ��ٸ� �� ���� �ش��ϴ� ���� ���ؼ� ����.

���� ���� ���ο� ž�� ������(���� ������ top�̾�����) sum�� ���Ѵ�.

���ڿ� �� ������ ����! sum ���

*/

// BOJ 3986 ���� �ܾ�
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
