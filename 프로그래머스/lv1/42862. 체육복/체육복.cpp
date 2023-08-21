#include <string>
#include <vector>
#include <iostream>

using namespace std;

int students[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 모든 학생 : 0
    // 안가져온애 : 1
    // 여벌 있는애 : 2
    
    answer = n;
    
    for(int i = 1 ; i <= n ; i++)
        students[i] = 0;
    
    for(auto& l : lost)
        students[l] = 1;
    
    for(auto& r : reserve) {
        if (students[r] == 1) {
            students[r] = 0;
            continue;
        }
        students[r] = 2;
    }
    
    for(int i = 1 ; i <= n ; i++) {
        if (students[i] == 1) {
            if (students[i-1] != 2 && students[i+1] != 2) {
                answer--;
                continue;
            }
            students[i] = 0;
            if (students[i-1] == 2) students[i-1] = 0;
            else if (students[i+1] == 2) students[i+1] = 0;
        }
    }
    
    return answer;
}