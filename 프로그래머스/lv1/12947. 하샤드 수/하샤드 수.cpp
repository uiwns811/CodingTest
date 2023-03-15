#include <string>
#include <vector>

using namespace std;

int GetSum(int x) {
    int sum = 0;
    while(x > 9) {
        sum += x % 10;
        x /= 10;
    }
    sum += x;
    return sum;
}

bool solution(int x) {
    bool answer = true;
    
    int sum = GetSum(x);
    
    answer = (x % sum == 0 ? true : false);

    
    return answer;
}