#include <string>
#include <vector>
#include <cmath>

using namespace std;

int GetGCD(int n, int m) {
    if (m == 0) return n;
    else return GetGCD(m, n % m);
}

int GetLCM(int n, int m) {
    return (n * m) / GetGCD(n, m);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if (n < m) {
        int temp = m;
        m = n;
        n = temp;
    }
    
    answer.emplace_back(GetGCD(n, m));
    answer.emplace_back(GetLCM(n, m));
    
    return answer;
}