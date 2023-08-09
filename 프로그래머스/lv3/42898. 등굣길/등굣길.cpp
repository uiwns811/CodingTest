#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int ways[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(auto& p : puddles)
        ways[p[0]][p[1]] = -1;
    
    int sum = 0;
    for (int i = 1 ; i < m + 1 ; i++) {
        for (int j = 1 ; j < n +1 ; j++) {
            if (i == 1 && j == 1) ways[i][j] = 1;
            else if (ways[i][j] != -1) {
                sum = 0;
                sum += ways[i-1][j] == -1 ? 0 : ways[i-1][j];
                sum += ways[i][j-1] == -1 ? 0 : ways[i][j-1];
                ways[i][j] = sum % 1000000007;
            }
        }
    }
    answer = ways[m][n];
    return answer;
}