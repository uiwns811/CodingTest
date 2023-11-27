#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    
    bool flag = false;
    int success = 0;
    int curTime = 1;
    int idx = 0;
    while(true) {
        if (success >= bandage[0]) {
            answer = min(answer + bandage[2], health);
            success = 0;
        }
        if (attacks[idx][0] == curTime) {
            answer -= attacks[idx][1];
            if (answer <= 0) {
                answer = -1;
                break;
            }
            success = 0;
            if (++idx >= attacks.size()) 
                break;
        }
        else {
	        answer = min(answer + bandage[1], health);
        	success++;
        }
        curTime++;
    }
    

    return answer;
}