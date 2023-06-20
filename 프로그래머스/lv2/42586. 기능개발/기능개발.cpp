#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> release;
    
    int lastDay = 0;
    for (int i = 0 ; i < progresses.size() ; i++) {
     	float fday = ((100 - progresses[i]) / (float)speeds[i]);
        fday = ((100 - progresses[i]) % speeds[i] == 0 ? fday : fday+=1);
        int day = (int)fday;
        if (lastDay >= day) {
            ++answer.back();
        }
        else {
            answer.emplace_back(1);
            lastDay = day;
        }
   	}
	    
    return answer;
}