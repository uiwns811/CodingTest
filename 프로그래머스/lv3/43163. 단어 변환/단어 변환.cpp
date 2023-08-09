#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool visited[51] = {false,};

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    // 최종 단어가 없을 때 칼차단
    if (find(words.begin(), words.end(), target) == words.end()) 
        return answer;
    
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));
    
    while(!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < words.size() ; i++) {
            if (visited[i]) continue;
            int diff = 0;
            for(int j = 0 ; j < cur.length() ; j++) {
                if (cur[j] != words[i][j])
                    diff++;
            }
            if (diff != 1) continue;
            visited[i] = true;
            cout << words[i] << cnt << endl;
            if (words[i] == target)
                return cnt + 1;
            else {
                answer++;
                q.push(make_pair(words[i], cnt+1));
            }
        }
    }
    
    return answer;
}