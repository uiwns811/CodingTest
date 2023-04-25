#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> vec = {"aya", "ye", "woo", "ma"};
    
    for (auto& b : babbling) {
        int i = 0;
        int visited = -1;
        bool bTrue = false;
        while(i < b.length()) {
            if (b.substr(i, 3) == "aya" && visited != 0) {
                i += 3;
                visited = 0;
            }
            else if (b.substr(i, 2) == "ye" && visited != 1) {
                i += 2;
                visited = 1;
            }
            else if (b.substr(i, 3) == "woo" && visited != 2) {
                i += 3;
                visited = 2;
            }
            else if (b.substr(i, 2) == "ma" && visited != 3) {
                i += 2;
                visited = 3;
            }
            else {
                bTrue = true;
                break;
            }
        }
        if (!bTrue)  {
            answer += 1;
        }
    }
    
    return answer;
}