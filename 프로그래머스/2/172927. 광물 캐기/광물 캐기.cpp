#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<vector<string>, int>& a, pair<vector<string>, int>& b) {
    return a.second > b.second;
}

int arr[3][3] = {{1, 5, 25}, {1, 1, 5}, {1, 1, 1}};
unordered_map<string, int> um;
unordered_map<string, int> weight;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    um["diamond"] = 0;
    um["iron"] = 1;
    um["stone"] = 2;
    
    weight["diamond"] = 25;
    weight["iron"] = 5;
    weight["stone"] = 1;
    
    vector<pair<vector<string>, int>> vec;
    
    int total = 0;
    for (int& p : picks) {
        total += p;
    }
    
    vector<string> v;
    int sum = 0;
    for (int i =0 ;i < minerals.size() ; i++) {
        v.push_back(minerals[i]);
        sum += weight[minerals[i]];
        if (i % 5 == 4 || i == minerals.size() - 1) {
            if (vec.size() < total) {
                vec.push_back(make_pair(v,sum));
                v.clear();
                sum = 0;
            }
        }
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    int idx = 0;
    while(picks[idx] <= 0) idx++;
    
    for (auto& v : vec) {
        for (string& s : v.first) {
            answer += arr[um[s]][idx];
        }
        picks[idx]--;
        while(picks[idx] <= 0) idx++;
    }
        
    return answer;
}