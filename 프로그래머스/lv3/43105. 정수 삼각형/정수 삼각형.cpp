#include <string>
#include <vector>

using namespace std;

int vec[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    
    vec[0][0] = triangle[0][0];
    
    for(int i = 1 ; i < size ; i++) {
        for(int j = 0 ; j < i + 1 ; j++) {
            if (j == 0) 
                vec[i][j] = vec[i-1][j] + triangle[i][j];
            else if (j == i)
                vec[i][j] = vec[i-1][j-1] + triangle[i][j];
            else
                vec[i][j] = vec[i-1][j-1] > vec[i-1][j] ? 
                vec[i-1][j-1] + triangle[i][j] : vec[i-1][j] + triangle[i][j];
        }
    }
    
    int max = 0;
    for (int i = 0 ; i < size ; i++) {
        if (max <= vec[size-1][i])
            max = vec[size-1][i];
    }
    answer = max;
    return answer;
}