#include <vector>
#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

bool isSosu(int n) {
    int num = sqrt(n);
    for (int i = 2 ; i <= num ; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> vec;
    
    for (int i = 0 ; i < nums.size() - 2 ; i++) {
        for (int j = i+1 ; j < nums.size() - 1 ; j++) {
            for (int k = j+1 ; k < nums.size() ; k++) {
                int cnt = nums[i] + nums[j] + nums[k];
                vec.emplace_back(cnt);
            }
        }
    }
    
    for (auto& s : vec) {
        if (isSosu(s)) answer += 1;
    }

    return answer;
}