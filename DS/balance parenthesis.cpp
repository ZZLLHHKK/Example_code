#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        int flag = 1;
        string s;
        getline(cin, s);
        if (s.empty()) {
            cout << "Yes" << '\n';
            continue;
        }
        
        stack<char> tmp;
        for (char c : s) {
            if (c == '{' || c == '(' || c == '[')
                tmp.push(c);
            else {
                if (tmp.empty()) {
                    flag = 0;
                    break;
                }
                if ((c == '}' && tmp.top() == '{') || (c == ')' && tmp.top() == '(') || (c == ']' && tmp.top() == '['))
                    tmp.pop();
                else {
                    flag = 0; 
                    break;
                }
            }
        }
        if (!tmp.empty()) 
            flag = 0;
        if (flag)
            cout << "Yes" << '\n';
        else 
            cout << "No" << '\n';
    }
}
