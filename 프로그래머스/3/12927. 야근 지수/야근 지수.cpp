#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for (int& w : works)
        pq.push(w);
    
    for (int i = 0 ; i < n ; i++){
        if (pq.empty()) break;
        int temp = pq.top();
        pq.pop();
        if (temp - 1 < 0) continue;
        pq.push(temp - 1);
    }
    
    while(!pq.empty()) {
        int work = pq.top();
        if (work < 1) break;
        pq.pop();
        answer += work * work;
    }
      
    return answer;
}