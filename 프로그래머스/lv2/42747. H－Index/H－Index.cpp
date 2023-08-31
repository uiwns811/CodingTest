#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    sort(citations.begin(), citations.end(), greater<int>());
    
    int cur = citations[0];
    while(cur > 0) {
        int cnt = 0;
        for (int j = 0 ; j < size ; j++) {
            if (citations[j] >= cur) {
                cnt++;
            }
        }
        if (cnt >= cur) {
            answer = cur;
            break;
        }
        cur--;
    }
    
    return answer;
}