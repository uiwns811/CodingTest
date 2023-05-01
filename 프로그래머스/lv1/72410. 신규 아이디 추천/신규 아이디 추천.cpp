#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for (auto& n : new_id) {
        if (isupper(n)) n = tolower(n);
    }
    
    // 2단계
    string temp = "";
    for (auto& n : new_id) {
        if (islower(n) || isdigit(n) || n == '-' || n == '_' || n == '.') {
            temp += n;
        }
    }
    new_id = temp;
    temp = "";
     
    // 3단계
    for (int i = 0 ; i < new_id.length() ; ) {
        if (new_id[i] == '.' && new_id[i-1] == '.') {
            new_id.erase(new_id.begin() + i);
        }
        else {
            i++;
        }
    }
    
    // 4단계
    if (new_id.front() == '.') new_id.erase(new_id.begin());
    if (new_id.back() == '.') new_id.erase(new_id.end() - 1, new_id.end());  
  
    // 5단계
    if(new_id.empty()) new_id = "a";
    
    // 6단계
    if (new_id.length() >= 16) new_id.erase(new_id.begin() + 15, new_id.end());
    if (new_id.back() == '.') new_id.erase(new_id.end()-1, new_id.end());

    // 7단계
    while(new_id.length() < 3) {
        new_id += (char)new_id.back();
    }
   
    answer = new_id;
    
    return answer;
}