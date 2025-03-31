#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool IsPrime(const std::vector<int>& _prime, const int _num)
{
    // 대상 숫자의 제곱근을 구합니다.
    int sqrtNum = sqrt(_num);
    for (const int& prime : _prime)
    {
        // 제곱근보다 큰 소수가 나올 때까지 나누어 떨어지지 않는다면 대상 숫자는 소수입니다.
        if (prime > sqrtNum) return true;
        
        // 역대 소수로 나누어 떨어지면 소수가 아닙니다.
        if (0 == _num % prime) return false;
    }
    // 누적 소수가 없거나 나누어 떨어지지 않는다면 소수입니다.
    return true;
}

int solution(int n) {
    
    std::vector<int> primes;
    for (int i = 2 ; i <= n ; ++i)
    {
        if (true == IsPrime(primes, i))
            primes.emplace_back(i);
    }
    
    return primes.size();
}