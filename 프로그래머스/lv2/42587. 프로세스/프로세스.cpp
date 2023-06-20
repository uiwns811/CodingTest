#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    
    for(int i= 0 ; i < priorities.size() ; i++) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()) {
        int id = q.front().first;
        int priority = q.front().second;
        if (priority == pq.top() && id == location) {
            answer++;
            break;
        }
        else if (priority == pq.top()) {
            pq.pop();
            q.pop();
            answer++;
        }
        else {
            q.pop();
            q.push(make_pair(id,priority));
        }
    }
    
    return answer;
}