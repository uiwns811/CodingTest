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
    map<int, string> mis;
    
    for (int i = 0 ; i < players.size() ; i++) {
        umsi[players[i]] = i+1;
        mis[i+1] = players[i];
    }
    
    for (auto& call : callings) {
    	int idx = umsi[call];
        string p = mis[idx-1];

        swap(umsi[call], umsi[p]);
        swap(mis[idx], mis[idx-1]);
    }
    
    for (auto& um : mis) {
        answer.emplace_back(um.second);
    }

    
    return answer;
}