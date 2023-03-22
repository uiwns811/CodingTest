#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
        
    for (auto& c : commands) {
        vector<int> temp;
        for (int i = c[0] - 1 ; i < c[1] ; i++) {
            temp.emplace_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.emplace_back(temp[c[2] - 1]);
    }
    return answer;
}