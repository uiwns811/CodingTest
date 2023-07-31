#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct compareByProcess
{
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, compareByProcess> pq;
    
    sort(jobs.begin(), jobs.end());
	int curTime = 0;
    int total = 0;
    
    int idx = 0;
    while(idx < jobs.size() || !pq.empty()) {
        if (idx < jobs.size() && jobs[idx][0] <= curTime) {
            pq.push(jobs[idx++]);
            continue;
        }
        
        if (!pq.empty()) {
            vector<int> curJob = pq.top();
            curTime += curJob[1];
            total += curTime - curJob[0];
            pq.pop();
        }
        else {
            curTime = jobs[idx][0];
        }
        
    }
    
    answer = total / jobs.size();
     
    
    return answer;
}