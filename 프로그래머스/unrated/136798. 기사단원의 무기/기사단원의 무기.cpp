#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> nums;
    for (int i = 1 ; i <= number ; i++) {
        // 약수 개수 구하기
        int cnt = 0;
        if (i == 1) cnt = 1;
        else {
            cnt = 2;
            for (int j = 2 ; j <= i/2 ; j++) {
                if (i % j == 0) cnt++;
            }
        }
        if (cnt <= limit) answer += cnt;
        else answer += power;
    }
    return answer;
}