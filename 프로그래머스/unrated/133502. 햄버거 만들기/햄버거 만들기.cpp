#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string str = "";
    
    for(auto& i : ingredient) {
        str += to_string(i);
        if (str.length() >= 4 && str.back() == '1') {
            if (str.substr(str.length() - 4, str.length()) == "1231") {
                str = str.substr(0, str.length() - 4);
                answer += 1;
            }
        }
    }
    
    return answer;
}