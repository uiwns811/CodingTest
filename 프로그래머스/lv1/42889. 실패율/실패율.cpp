#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, double> A, pair<int, double> B) {
    if (A.second == B.second) {
        return A.first < B.first;
    }
    else {
        return A.second > B.second;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> scores;
    
    for (int i = 1 ; i < N+1 ; i++) {
        int total = 0;
        int fail = 0;
        double rate = 0.0f;
        for (int j = 0 ; j < stages.size() ; j++) {
            if (stages[j] > i) {
                total += 1;
            }
            else if (stages[j] == i) {
                total += 1;
                fail += 1;
            }
        }
        if (total == 0) rate = 0;
        else rate = (double)fail / total;
        
        scores.emplace_back(make_pair(i, rate));
    }
  
    sort(scores.begin(), scores.end(), compare);
    
    for (auto& s : scores) {
        answer.emplace_back(s.first);
    }
    
    return answer;
}