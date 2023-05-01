#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> umsi;
    map<int, string> umis;
    
    for (int i = 0 ; i < players.size() ; i++) {
        umsi[players[i]] = i+1;
        umis[i+1] = players[i];
    }
    
    for (auto& call : callings) {
    	int idx = umsi[call];
        string p = umis[idx-1];
        umsi[call] -= 1;    
        umsi[p] += 1;
        umis[idx] = p;
        umis[idx-1] = call;
    }
    
    for (auto& um : umis) {
        answer.emplace_back(um.second);
    }

    
    return answer;
}