#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto& sc : scoville) {
        pq.push(sc);
    }
    
    while(pq.top() < K) {
        int min = pq.top();
        pq.pop();
        int next = pq.top();
        pq.pop();
        int newFood = min + next * 2;
        pq.push(newFood);
        answer++;
        
        if(pq.size() < 2) {
          	if(pq.top() < K) {
                answer = -1;
                break;
            }
        }
    }
    
    return answer;
}