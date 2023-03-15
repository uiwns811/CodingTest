#include <string>
#include <vector>
#include <cmath>

using namespace std;

int GetDivisorCnt(int num) {
    vector<int> divisors;
    
    if (num == 1) return 1;
    
    int sn = sqrt(num);
    int cnt = 0;
    
    for (int i = 1 ; i <= sn ; i++) {
        if (num % i == 0) {
            divisors.emplace_back(i);
            cnt += 1;
        }
    }
    
    cnt *= 2;
    
    for (auto& d : divisors) {
        if (d * d == num)
            cnt -= 1;
    }
    
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    int divisor = 0;
    
    for (int i = left ; i <= right ; i++) {
        answer = (GetDivisorCnt(i) % 2 == 0 ? answer + i : answer - i);
    }
    
    
    return answer;
}