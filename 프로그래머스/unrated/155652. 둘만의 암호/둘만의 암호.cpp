#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (char c : s) {
        for (int i = 0 ; i < index ; ) {
            c++;
            if (c > 'z') c = 'a';
            if (skip.find(c) != string::npos) continue;
            i++;
            cout << c << endl;
        }
        answer += c;
    }
    
    return answer;
}