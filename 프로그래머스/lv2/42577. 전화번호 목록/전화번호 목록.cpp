#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> um;
    
    for(auto& pb : phone_book) {
        um[pb] = 1;
    }
    
    for (int i = 0 ; i < phone_book.size() ; i++) {
        string str = "";
        for (int j = 0 ; j < phone_book[i].length() ; j++) {
            str += phone_book[i][j];
            if (um[str] && str != phone_book[i]) {
                answer = false;
                break;
			}
        }
    }
    
    return answer;
}