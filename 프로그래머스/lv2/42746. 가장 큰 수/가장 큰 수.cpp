#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vec;
    for(auto& num : numbers) {
        vec.emplace_back(to_string(num));
    }
    sort(vec.begin(), vec.end(), compare);
    
    for(auto& v : vec) {
        answer += v;
    }
    
    if (answer[0] == '0')
        answer = '0';
    
    return answer;
}