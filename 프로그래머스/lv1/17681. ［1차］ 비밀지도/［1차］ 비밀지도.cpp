#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 공백 공백 = 공백
// 공백 벽 = 벽
// 벽 벽 = 벽

vector<int> GetBinary(int n, int num) {
    vector<int> binary;
    
    while(num > 1) {
        binary.emplace_back(num % 2);
        num /= 2;
    }
    binary.emplace_back(num);
    
    while(binary.size() != n) {
        binary.emplace_back(0);
    }
    
    reverse(binary.begin(), binary.end());
    return binary;
    
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int j = 0 ; j < n ; j++) {
        string line = "";
        vector<int> a = GetBinary(n, arr1[j]);
        vector<int> b = GetBinary(n, arr2[j]);

        for (int k = 0 ; k < n ; k++) {
            string space = (a[k] == 0 && b[k] == 0 ? " " : "#");
            line += space;
        }
        answer.emplace_back(line);
    }
    return answer;
}