#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <iostream>

using namespace std;

unordered_map<string, string> um;

void MakeMap() {
    um["zero"] = "0";
    um["one"] = "1";
    um["two"] = "2";
    um["three"] = "3";
    um["four"] = "4";
    um["five"] = "5";
    um["six"] = "6";
    um["seven"] = "7";
    um["eight"] = "8";
    um["nine"] = "9";
}

int solution(string s) {
    int answer = 0;
    string str;
    string temp;
    
    MakeMap();
    
    for (int i = 0 ; i < s.length() ; i++) {
        if(isdigit(s[i])) {
            str += s[i];
        }
        else {
            temp += s[i];
        }
        if (um.find(temp) != um.end()) {
            str += um[temp];
            temp = "";
        }
    }
    answer = atoi(str.c_str());
    
    return answer;    
}