#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> scores;
    int scoreCnt = -1;
    string tempScore = "";
    
    for (int i = 0 ; i < dartResult.length() ; i++) {
        if (isdigit(dartResult[i])) {
            tempScore += dartResult[i];
        }
        else {
            if (!tempScore.empty()) {
                scores.emplace_back(stoi(tempScore));
                tempScore = "";
                scoreCnt++;
            }
            if (isalpha(dartResult[i])) {
                if (dartResult[i] == 'S') {

                }
                else if (dartResult[i] == 'D') {
                    scores[scoreCnt] = pow(scores[scoreCnt], 2);
                }
                else if (dartResult[i] == 'T') {
                    scores[scoreCnt] = pow(scores[scoreCnt], 3);
                }
            }
            else if (dartResult[i] == '#') {
                scores[scoreCnt] *= -1;
            }
            else if (dartResult[i] == '*') {
                scores[scoreCnt] *= 2;
                if (scoreCnt > 0) {
                    scores[scoreCnt-1] *= 2;
                }
            }
        }
    }
        
    for (auto& s : scores) {
        answer += s;
    }
    
    return answer;
}