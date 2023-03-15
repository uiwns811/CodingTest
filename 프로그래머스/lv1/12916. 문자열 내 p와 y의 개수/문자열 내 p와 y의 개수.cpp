#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int pCnt = 0;
    int yCnt = 0;
    
    for (int i = 0 ; i < 50 ; i++) {
        if (s[i] =='p' || s[i] == 'P') pCnt += 1;
        else if (s[i] == 'y' || s[i] == 'Y') yCnt += 1;
    }
    
    answer = (pCnt == yCnt ? true : false);
    
    return answer;
}