#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[201] {false};
int connected = 0;

void dfs(vector<vector<int>>& com, int n, int cur)
{
    visited[cur] = true;
    
    for(int i = 0 ; i < n ; i++) {
        if (!visited[i] && com[cur][i] == 1) {
            dfs(com, n, i);
        }
    }    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0 ; i < n ; i++) {
        if (!visited[i]) {
    		dfs(computers, n, i);
            answer++;
        }
    }
    return answer;
}