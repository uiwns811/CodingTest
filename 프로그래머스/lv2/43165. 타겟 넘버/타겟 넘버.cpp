#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
vector<int> nums;

void GetNum(int curNum, int idx, int target, int size) 
{
    //cout << curNum << ", " << idx << endl;
    if (idx == size - 1) {
        if (curNum == target) {
            answer++;
        }
        return;
    }
    GetNum(curNum + nums[idx + 1], idx + 1, target, size);
    GetNum(curNum - nums[idx + 1], idx + 1, target, size);
}

int solution(vector<int> numbers, int target) {    
    nums = numbers;
    
    GetNum(nums[0], 0, target, numbers.size());
    GetNum(-nums[0], 0, target, numbers.size());
   
    return answer;
}