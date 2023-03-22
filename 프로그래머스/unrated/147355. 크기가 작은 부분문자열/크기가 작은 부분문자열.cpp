#include <string>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int size = p.length();
    for (int i = 0 ; i < t.length() - size + 1 ; i++) {
        bool same = true;
        for (int j = 0 ; j < size ; j++) {
            if (t[i + j] > p[j]) {
                same = false;
                break;
            }
            else if (t[i + j] < p[j]) {
                same = false;
                answer += 1;
                break;
            }
        }
        if (same)
            answer += 1;
    }
    
    return answer;
}