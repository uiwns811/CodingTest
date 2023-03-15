#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long double x = sqrt(n);
    
    answer = (pow(x, 2) == n ? pow(x+1, 2) : -1);
    
    return answer;
}

