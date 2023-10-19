#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(pair<bool, string>& a, pair<bool, string>& b){
    return a.second < b.second;
}

unordered_map<string, vector<pair<bool, string>>> graph;

vector<string> answer;
vector<string> v;
vector<string> temp;
int total_size = 0;
int cnt = 0;
bool flag = false;

void DFS(string start) {
    v.push_back(start);
    // cout << start << " : "  << cnt << endl;
    for (pair<bool, string>& next : graph[start]) {
        if (next.first == false) {
            cnt++;
            next.first = true;
            DFS(next.second);
            next.first = false;
            
            if (cnt == total_size && !flag) {
                for (auto& ve : v)
                    answer.push_back(ve);
                flag = true;
                return;
            }
            else {
                v.pop_back();
                cnt--;
            }
        }
    }
    if (!flag && cnt == total_size) { 
        for (auto& ve : v)
            answer.push_back(ve);
        flag = true;
        return;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for(vector<string>& t : tickets) {
        graph[t[0]].push_back(make_pair(false, t[1]));
        total_size++;
    }
    
    for(auto& g : graph) {
        sort(g.second.begin(), g.second.end(), compare);
    }
    
    DFS("ICN");
    
    return answer;
}