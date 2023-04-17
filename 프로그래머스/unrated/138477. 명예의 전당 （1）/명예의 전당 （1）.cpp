#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> temp;
    
    for (int i = 0 ; i < score.size() ; i++) {
        temp.push(score[i]);
        if (temp.size() > k) {
            temp.pop();
        }
        answer.emplace_back(temp.top());
    }
    
    return answer;
}