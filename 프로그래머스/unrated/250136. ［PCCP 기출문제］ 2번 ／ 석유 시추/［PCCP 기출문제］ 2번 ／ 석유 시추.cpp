#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int n, m;

int arr[510][510];
bool visited[510][510] = {false,};

int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int dp[501];

int GetOil(int x, int y, int cnt, set<int>& s) {
    bool flag = false;
    for (int i = 0 ; i < 4 ; i++) {
        int nextX = x + dir[0][i];
        int nextY = y + dir[1][i];
        
        if (arr[nextX][nextY] && !visited[nextX][nextY]) {
            flag = true;
            visited[nextX][nextY] = true;
            s.insert(nextY);
        	cnt = GetOil(nextX, nextY, cnt + 1, s);
        }
    }
    if (!flag) {
        return cnt;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    n = land.size();
    m = land[0].size();
    
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            arr[i+1][j+1] = land[i][j];
        }
    }
    
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= m ; j++) {
            if (arr[i][j] && !visited[i][j]) {
                visited[i][j] = true;
                set<int> s;
                s.insert(j);
                int cnt = GetOil(i, j, 1, s);
                for (auto iter = s.begin() ; iter != s.end() ; iter++)
                    dp[*iter] += cnt;
            }
        }
    }
    
    for (int i = 1 ; i <= m ; i++) {
        answer = max(answer, dp[i]);
    }
    
    return answer;
}