#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool compare(string A, string B) {
    if (A[N] == B[N]) {
        return A < B;
    }
    else {
        return A[N] < B[N];
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    N = n;
    
    sort(strings.begin(), strings.end(), compare);
    answer = strings;
    
    return answer;
}