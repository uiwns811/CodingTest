#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> pick{{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    
    vector<int> cnts{0, 0, 0};
    
    for (int i = 0 ; i < answers.size() ; i++) {
        if (answers[i] == pick[0][i % 5]) cnts[0] += 1;
        if (answers[i] == pick[1][i % 8]) cnts[1] += 1;
        if (answers[i] == pick[2][i % 10]) cnts[2] += 1;
    }
    
    int max = *max_element(cnts.begin(), cnts.end());
    
    for (int i = 0 ; i < 3 ; i++) {
        if (cnts[i] == max) {
            answer.emplace_back(i+1);
        }
    }    
    return answer;
}