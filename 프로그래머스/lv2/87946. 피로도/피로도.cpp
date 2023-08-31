#include <string>
#include <vector>

using namespace std;

int total = -1;
bool visited[9] = {false, };

void DFS(int cur, int idx, vector<vector<int>>& dg) 
{
    if (idx > total) total = idx;
    for(int i = 0 ; i < dg.size() ; i++) {
        if (cur >= dg[i][0] && visited[i] == false) {
            visited[i] = true;
            DFS(cur - dg[i][1], idx + 1, dg);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    DFS(k, 0, dungeons);
    
    answer = total;
    
    return answer;
}