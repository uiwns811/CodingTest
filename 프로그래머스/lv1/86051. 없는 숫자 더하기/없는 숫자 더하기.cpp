#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    for (int i = 0 ; i < 10 ; i++) {
        answer += i;
    }
    
    for (auto& n : numbers) {
        answer -= n;
    }
    
    return answer;
}