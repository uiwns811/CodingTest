#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());    
    
    for (int i = 0 ; i < phone_book.size() - 1 ; i++) {
        int size = phone_book[i].length();
        string str = phone_book[i];
        if (str == phone_book[i+1].substr(0, size)) {
            answer = false;
            break;
        }
        if (!answer) break;
    }
    return answer;
}