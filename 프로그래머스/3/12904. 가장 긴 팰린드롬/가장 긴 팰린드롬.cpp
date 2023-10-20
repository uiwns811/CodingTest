#include <iostream>
#include <string>
using namespace std;

int isPalindrome(string& s, int left, int right)
{
    while(left >= 0 && right < s.length()) {
        if (s[left] != s[right]) break;
        left--;
        right++;
    }
    return right - left - 1;
}

int solution(string s)
{
    int answer=0;
    
    for (int i = 0 ; i < s.length() ; i++) {
        answer = max(answer, isPalindrome(s, i, i));
      	answer = max(answer, isPalindrome(s, i-1, i));
	}

    return answer;
}