#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int move = n - 1;
    
    for(int cur = 0 ; cur < n ; cur++) {
        // 1번 : 냅다 탐색
        answer += min(name[cur] - 'A', 'Z' - name[cur] + 1);
        
        // 2번 : 다음 탐색 방향 정하기
        int next = cur + 1;
        while(name[next] == 'A' && next <= n - 1)
            next++;
        
        move = min(move, min(2 * cur + n - next, 2 * n - 2 * next + cur));
    }
    answer += move;
    
    return answer;
}