#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0 ; i < n ; i++) {
        arr1[i] = arr1[i] | arr2[i];        // arr1과 arr2의 비트연산한 값이 나옴
        string line;
        
        while(line.length() != n) {
            if (arr1[i] % 2 == 0) line = " " + line;
            else line = "#" + line;
            arr1[i] /= 2;
        }
        
        
        answer.emplace_back(line);
    }
    
    return answer;
}