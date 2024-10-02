//
// Created by 박재영 on 2024. 9. 29..
//
#include <bits/stdc++.h>

using namespace std;

//void parse(string& tmp, deque<int>& d){
//    int cur = 0;
//    for(int i = 1; i+1 < tmp.size(); i++)
//    {
//        if(tmp[i] == ','){
//            d.push_back(cur);
//            cur = 0;
//        }
//        else{
//            cur = 10 * cur + (tmp[i] - '0');
//        }
//    }
//    if(cur != 0)
//        d.push_back(cur);
//}
//
//void print_result(deque<int>& d){
//    cout << '[';
//    for(int i = 0; i < d.size(); i++)
//    {
//        cout << d[i];
//        if(i+1 != d.size())
//            cout << ',';
//    }
//    cout << "]\n";
//}
//
//int t;
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> t;
//    while(t--){
//        deque<int> d;
//        int rev = 0;
//        int n;
//        bool isWrong = false;
//        string query, tmp;
//        cin >> query;
//        cin >> n;
//        cin >> tmp;
//        parse(tmp, d);
//        for(char c : query)
//        {
//            if(c == 'R')
//                rev = 1 - rev;
//            else{
//                if(d.empty()){
//                    isWrong = true;
//                    break;
//                }
//                if(!rev) d.pop_front();
//                else d.pop_back();
//            }
//        }
//        if(isWrong)
//            cout << "error\n";
//        else{
//            if(rev) reverse(d.begin(), d.end());
//            print_result(d);
//        }
//    }
//}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string functions;
        cin >> functions;

        int m;
        cin >> m;

        string arr;
        cin >> arr;

        deque<int> deque;
        string buffer;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr.size() == 2) break;
            if (arr[i] == ',' || arr[i] == ']') {
                deque.push_back(stoi(buffer));
                buffer.clear();
                continue;
            }
            buffer += arr[i];

        }

        bool isReversed = false;
        bool isError = false;
        for (int i = 0; i < functions.size(); ++i) {
            if (functions[i] == 'R') {
                if (isReversed) isReversed = false;
                else isReversed = true;
            }
            else {
                if (deque.empty()) {
                    cout << "error" << "\n";
                    isError = true;
                    break;
                }
                if (isReversed) deque.pop_back();
                else { deque.pop_front(); }
            }
        }

        if (isError) continue;

        cout << "[";
        if (!deque.empty()) {
            int size = deque.size();
            if (isReversed) {
                for (int i = 0; i < size - 1; ++i) {
                    cout << deque.back() << ",";
                    deque.pop_back();
                }
                cout << deque.back();
            } else {
                for (int i = 0; i < size - 1; ++i) {
                    cout << deque.front() << ",";
                    deque.pop_front();
                }
                cout << deque.front();
            }
        }
        cout << "]" << "\n";
    }
}