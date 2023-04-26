#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<vector<int>> lines;
    stack<int> buckets;
    
    for (int i = 0 ; i < board.size() ; i++) {
        vector<int> vec;
        for (int j = 0 ; j < board.size() ; j++) {
            if (board[j][i] != 0) {
                vec.emplace_back(board[j][i]);
            }
        }
        lines.emplace_back(vec);
    }
    
    for (auto& m : moves) {
        if (lines[m-1].empty()) continue;
        int doll = lines[m-1][0];
        lines[m-1].erase(lines[m-1].begin(), lines[m-1].begin() + 1);
        
        if (buckets.empty()) buckets.push(doll);
        else if (buckets.top() != doll) buckets.push(doll);
        else {
            buckets.pop();
            answer += 2;
        }
    }
    
    return answer;
}