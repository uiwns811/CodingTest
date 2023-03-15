#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int size = arr1.size();
    for (int i = 0 ; i < size ; i++) {
        vector<int> sum;
        int size2 = arr1[i].size();
        for (int j = 0 ; j < size2 ; j++) {
        sum.emplace_back(arr1[i][j] + arr2[i][j]);            
        }
        answer.emplace_back(sum);
    }
    
    return answer;
}