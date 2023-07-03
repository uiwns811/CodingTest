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
        if (pq.size() < 2) {
            answer = -1;
            break;
        }
        int min = pq.top();
        pq.pop();
        int next = pq.top();
        pq.pop();
        int newFood = min + next * 2;
        pq.push(newFood);
        answer++;
    }
    
    return answer;
}