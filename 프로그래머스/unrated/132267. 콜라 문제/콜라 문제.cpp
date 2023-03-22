#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int get = 0;
    int sell = 0;
    
    while(n >= a) {
        sell = (n / a) * a;
        get = (n / a) * b;
        n = n - sell + get;
        answer += get;
    }
    
    
    return answer;
}