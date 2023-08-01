#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void GetNum(int curNum, int idx, int target, vector<int>& vec) 
{
    if (idx == vec.size() - 1) {
        if (curNum == target) {
            answer++;
        }
        return;
    }
    GetNum(curNum + vec[idx + 1], idx + 1, target, vec);
    GetNum(curNum - vec[idx + 1], idx + 1, target, vec);
}

int solution(vector<int> numbers, int target) { 
    
    GetNum(numbers[0], 0, target, numbers);
    GetNum(-numbers[0], 0, target, numbers);
   
    return answer;
}