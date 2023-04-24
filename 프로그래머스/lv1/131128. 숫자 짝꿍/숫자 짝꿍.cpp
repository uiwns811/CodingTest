#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";    
    map<char, int> mx;
    map<char, int> my;
    
    for (int i = 0 ; i < X.length() ; i++) {
        mx[X[i]] += 1;
    }
    
    for (int i = 0 ; i < Y.length() ; i++) {
        my[Y[i]] += 1;
    }
    
    for (int i = 9 ; i >= 0 ; i--) {
        for (int j = 0 ; j < min(mx[i + '0'], my[i+'0']) ; j++)  {
            answer += i + '0';
        }
    }
    
    if (answer == "") answer = "-1";
    else if (answer[0] == '0') answer = "0";
    
    return answer;
}