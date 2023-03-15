#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> num;
    while(n > 2) {
        num.emplace_back(n % 3);
        n /= 3;
    }
    num.emplace_back(n);
    
    int size = num.size();
    for (int i = 0 ; i < size ; i++) {
        answer += num[size - i - 1] * pow(3, i);
    }
    
    return answer;
}