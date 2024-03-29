#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n > 9) {
        answer.emplace_back(n % 10);
        n /= 10;
    }        
    answer.emplace_back(n);
    
    return answer;
}