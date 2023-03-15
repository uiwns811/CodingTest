#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    int size = s.length();
    
    if (size != 4 && size != 6) {
        answer = false;
    }
    else {
        for (int i = 0 ; i < size ; i++) {
            if (s[i] < 48 || s[i] > 57) { 
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}