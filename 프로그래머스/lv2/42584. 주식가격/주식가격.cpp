#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> q;
    
    for(auto& p : prices) {
        q.push(p);
    }
    
    for(int i = 0 ; i < prices.size() ; i++) {
    	bool flag = false;
        int cur = q.front();
        q.pop();
        for(int j = 0 ; j < q.size() ; j++) {
            if (cur > prices[i + j]) {
                flag = true;
                answer.emplace_back(j);
                break;
            }
        }
        if(!flag)
            answer.emplace_back(q.size());
    }

    return answer;
}