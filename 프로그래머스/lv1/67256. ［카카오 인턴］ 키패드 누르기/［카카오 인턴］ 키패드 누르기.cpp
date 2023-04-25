#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int GetDistance(int a, int b) {
    // return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
    return abs((a-1)%3 - (b-1)%3) + abs((a-1)/3 - (b-1)/3);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lh = 10;
    int rh = 12;
    
    for (auto& num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += 'L';
            lh = num;
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += 'R';
            rh = num;
        }
        else {
            if (num == 0) num = 11;
            
            int ld = GetDistance(lh, num);
            int rd = GetDistance(rh, num);
            
            if (ld < rd) {
                answer += 'L';
                lh = num;
            }
            else if (ld > rd) {
                answer += 'R';
                rh = num;
            }
            else {
                if (hand == "right") {
                    answer += 'R';
                    rh = num;
                }
                else {
                    answer += 'L';
                    lh = num;
                }
            }
        }
    }
    return answer;
}