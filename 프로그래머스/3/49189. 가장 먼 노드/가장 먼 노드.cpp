#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> cost;
vector<vector<int>> graph;
bool visited[20001] = {false,};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (int i = 0 ; i <= n ; i++) {
        graph.emplace_back(vector<int>());
        cost.emplace_back(0);
    }
    
    for(vector<int>& e : edge) {
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
    }
    
    queue<int> q;
    cost[1] = 0;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int& next : graph[cur]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                cost[next] = cost[cur]+1;
            }
        }
    }
    
    sort(cost.begin(), cost.end(), greater<int>());
    int max = *cost.begin();
    for (int& c : cost) {
        if (c == max) answer++;
        else break;
    }
   
    return answer;
}