#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> cnt {0, 0};
    char start = s[0];
    
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == start) cnt[0]++;
        else cnt[1]++;
        
        if (cnt[0] == cnt[1]) {
            answer += 1;
            start = s[i+1];
            cnt[0] = 0;
            cnt[1] = 0;
        }
    }
    
    if (cnt[0] != cnt[1]) answer += 1;
    
    return answer;
}