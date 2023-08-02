#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    queue<pair<int, int>> bfs;
	bool visited[101][101] {false};
    int dist[101][101] {-1};
    
    int dx[4] {-1, 0, 1, 0};
	int dy[4] {0, -1, 0, 1};

   	int n = maps[0].size();
    int m = maps.size();
   
    bfs.push(make_pair(0,0));
    visited[0][0] = true;
    dist[0][0] = 1;
    while(!bfs.empty()) {
        int curx = bfs.front().first;
        int cury = bfs.front().second;
        bfs.pop();
   		for(int i = 0 ;i < 4 ; i++) {
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
            if (nextx < 0 || nextx > m-1 || nexty < 0 || nexty > n-1) continue;
            if (maps[nextx][nexty] == 0) continue;
            if (!visited[nextx][nexty]) {
                bfs.push(make_pair(nextx, nexty));
                visited[nextx][nexty] = true;
                dist[nextx][nexty] = dist[curx][cury] + 1;
            }
    	}
    }
    if (!visited[m-1][n-1]) 
        answer = -1;
    else
        answer = dist[m-1][n-1];
    return answer;
}