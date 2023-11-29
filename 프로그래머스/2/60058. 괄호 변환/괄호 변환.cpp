#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string answer = "";

bool isCorrect(string s) {
    if (s[0] == ')') return false;
    
	stack<char> st;
    for (char& c : s) {
        if (c == '(') {
            st.push(c);
        }
        else {
            while(!st.empty()) {
                char temp = st.top();
                if (temp == '(') 
                    st.pop();
                else
                    return false;
            }
        }
    }
    if (!st.empty()) return false;
    return true;
}

void Divide(string s) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == '(') cnt1++;
        else cnt2++;
        if (cnt1 == cnt2) {
            string u = s.substr(0, i+1);
            string v = s.substr(i+1, s.size() - i + 1);
            if (isCorrect(u)) {
                answer += u;
                Divide(v);
                return;
            }
            else {
                answer += '(';
                Divide(v);
                answer += ')';
                for (int j = 1 ; j < u.size()-1 ; j++) {
                    if (u[j] == '(') answer += ')';
                    else answer += '(';
                }
                return;
            }
        }
    }
}

string solution(string p) {
    Divide(p);
    return answer;
}