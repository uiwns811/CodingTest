#include <string>
#include <vector>

using namespace std;

// [w, h] 중에서 더 큰 것을 w으로 넣는다
// 벡터의 원소들 중 가장 큰 w, h를 찾는다

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxW = 0, maxH = 0;
    
    for (auto& s : sizes) {
        if (s[1] > s[0]) {
            int temp = s[0];
            s[0] = s[1];
            s[1] = temp;
        }
        if (s[0] > maxW)
            maxW = s[0];
        if (s[1] > maxH)
            maxH = s[1];
    }
    
    answer = maxW * maxH;
    
    return answer;
}