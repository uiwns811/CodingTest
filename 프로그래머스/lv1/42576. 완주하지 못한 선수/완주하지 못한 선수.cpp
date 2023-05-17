#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> s;
    
    for(auto& p : participant) {
        s.insert(p);
    }
    
    for (auto& c : completion) {
        auto it = s.find(c);
        if (it != s.end()) {
            s.erase(it);
        }
    }
    
    for (auto& str : s) {
        answer = str;
    }
    
    return answer;
}