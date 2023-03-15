#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int cnt = absolutes.size();
    
    for (int i = 0 ; i < cnt ; i++) {
        answer = (signs[i] == true ? answer + absolutes[i] : answer - absolutes[i]);
    }
    
    
    return answer;
}