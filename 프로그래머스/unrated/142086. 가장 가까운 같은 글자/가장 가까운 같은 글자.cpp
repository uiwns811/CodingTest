#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<char> vec;
    
    for (int i = 0 ; i < s.length() ; i++) {
        int num = -1;
        for (int j = 0 ; j < vec.size() ; j++) {
            if (s[i] == vec[j]) {
                num = i - j;
            }
        }
        answer.emplace_back(num);
        vec.emplace_back(s[i]);
    }
    
    return answer;
}