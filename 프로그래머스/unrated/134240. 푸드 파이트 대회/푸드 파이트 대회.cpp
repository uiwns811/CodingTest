#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    answer += "0";
    for (int i = food.size() - 1 ; i > 0 ; i--) {
        if (food[i] < 2) continue;
        for (int j = 0 ; j < food[i] / 2 ; j++) {
            answer += to_string(i);
            answer = to_string(i) + answer;
        }
    }
    return answer;
}