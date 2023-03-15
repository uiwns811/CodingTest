#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

int solution(string s) {
    int answer = 0;
    int length = s.length();
    

    
    string ss(s);
    bool isMinus = false;
    
    for (int i = 0 ; i < length ; i++) {
        if (s[i] == '+')
            break;
        if (s[i] == '-') {
            ss = &s[i + 1];
            isMinus = true;
        }
    }
    
    answer = atoi(&ss[0]);
    if (isMinus) answer = -answer;
    
    return answer;
}