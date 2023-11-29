#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> vec;
    while(1) {
        auto iter = s.find(' ');
        vec.push_back(atoi(s.substr(0, iter).c_str()));
        if (iter == string::npos) break;
        s = s.substr(iter + 1, s.size() - iter);
    }
	
    sort(vec.begin(), vec.end());
    answer += to_string(vec.front());
    answer += ' ';
    answer += to_string(vec.back());
    
    return answer;
}