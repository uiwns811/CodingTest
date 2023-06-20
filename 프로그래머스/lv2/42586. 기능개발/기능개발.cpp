#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> release;
    
    for (int i = 0 ; i < progresses.size() ; i++) {
     	int cnt = 1;
        while(progresses[i] + speeds[i] * cnt < 100)
            cnt++;
        release.emplace_back(cnt);
    }
    
    int lastRelease = release[0];
    int releaseCnt = 0;
    for(int i = 0 ; i < release.size() ; i++) {
        if (release[i] <= lastRelease) {
            releaseCnt++;
        }
        else {
            lastRelease = release[i];
            answer.emplace_back(releaseCnt);
            releaseCnt = 1;
        }
    }
    answer.emplace_back(releaseCnt);
    
    return answer;
}