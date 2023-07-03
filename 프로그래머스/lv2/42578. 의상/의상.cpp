#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    
    for(auto& cl :  clothes) {
        um[cl[1]]++;
    }
    
    for(auto iter = um.begin() ; iter != um.end() ; iter++) {
        answer *=(iter->second+1);
    }
    answer -= 1;
    
    return answer;
}