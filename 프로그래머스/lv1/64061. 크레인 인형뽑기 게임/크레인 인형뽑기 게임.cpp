#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> buckets;

    for (auto& m : moves) {
        for (int j = 0 ; j < board.size() ; j++ ) {
            int doll = board[j][m-1];
            if (doll == 0) continue;
            else {
                board[j][m-1] = 0;
                if (buckets.empty()) buckets.push(doll);
                else if (buckets.top() != doll) buckets.push(doll);
                else {
                    buckets.pop();
                    answer += 2;
                }
                break;
            }
        }  
    }
    return answer;
}