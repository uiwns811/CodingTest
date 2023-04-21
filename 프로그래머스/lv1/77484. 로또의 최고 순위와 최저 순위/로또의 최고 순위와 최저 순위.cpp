#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int score = 0;
    int zero = 0;
    
    for(auto& lotto : lottos) {
        if (lotto == 0) {
            zero += 1;
        }
        else if (find(win_nums.begin(), win_nums.end(), lotto) != win_nums.end()) {
            score += 1;
        }
    }
    
    int max = 7 - score - zero;
    int min = 7 - score;
    
    if (max < 1) max = 1;
    if (max > 6) max = 6;
    if (min < 1) min = 1;
    if (min > 6) min = 6;
    
    answer.emplace_back(max);
    answer.emplace_back(min);
    
    return answer;
}