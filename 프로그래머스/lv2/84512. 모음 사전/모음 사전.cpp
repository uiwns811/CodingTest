#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dictionary;
string arr[5] = {"A", "E", "I", "O", "U"};

void addWord(string str)
{
    if (str.size() > 5) return;
    dictionary.emplace_back(str);
    for (int i =0  ; i < 5 ; i++) {
        addWord(str + arr[i]);
    }
}

void MakeDictionary()
{
    for (int i = 0 ; i < 5 ; i++) {
        addWord(arr[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
    MakeDictionary();
    
    for (int i = 0 ; i < dictionary.size() ; i++) {
        if (dictionary[i] == word) answer = i+1;
    }
    
    return answer;
}