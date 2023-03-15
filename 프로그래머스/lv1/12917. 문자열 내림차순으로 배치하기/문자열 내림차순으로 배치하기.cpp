#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<char> vec;
    
    int length = s.length();
    for (int i = 0 ; i < length ; i++) {
        vec.emplace_back(s[i]);
    }
    sort(vec.begin(), vec.end(), greater<>());
    
    for (auto& v : vec) {
        answer += v;
    }
    
    return answer;
}