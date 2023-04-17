#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for (int i = 0 ; i < photo.size() ; i++) {
        int score = 0;
        for (auto& p : photo[i]) {
            for (int j = 0 ; j < name.size() ; j++) {
                if (strcmp(p.c_str(), name[j].c_str()) == 0) {
                    score += yearning[j];
                }
            }
        }
        answer.emplace_back(score);
    }
    
    return answer;
}