#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    vector<int> months = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int cnt = -1;
    for (int i = 0 ; i < a - 1 ; i++) {
        cnt += months[i];
    }
    cnt += b;

    int result = cnt % 7;
    
    answer = days[result];
    
    return answer;
}