#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    if (num == 1) return answer;
    
    long long temp(num);
    
    while(true) {
        temp = (temp % 2 == 0 ? temp / 2 : temp * 3 + 1);
        answer += 1;
        
        if (temp == 1) break;
        
        if (answer >= 500) {
            answer = -1;
            break;
        }
    }
    
    return answer;
}