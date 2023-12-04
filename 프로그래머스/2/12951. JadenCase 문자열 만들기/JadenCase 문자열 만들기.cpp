#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if (isalpha(s[0])) answer += toupper(s[0]);
    else answer += s[0];
    for (int i = 1 ;i < s.size() ; i++) {
       	if (s[i] != ' ') {
            if (s[i-1] == ' ') answer += toupper(s[i]);
        	else answer += tolower(s[i]);
        }
        else answer += ' ';
    }
    return answer;
}