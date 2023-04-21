#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int cur = 0;
    
    for (int i = 0 ; i < section.size(); i++) {
        if (cur < section[i]) {
            answer += 1;
            cur = section[i] + m - 1;
        }
        
    }
    
    return answer;
}