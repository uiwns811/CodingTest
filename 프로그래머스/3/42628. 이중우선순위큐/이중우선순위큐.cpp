#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxPq;
    priority_queue<int, vector<int>, greater<int>> minPq;
    multiset<int> ms;
    
    string str = "";
    int num = 0;
    int maxNum = 0;
    int minNum = 0;
    for (string& op : operations) {
        if (op[0] == 'I') {
            str = op.substr(2, op.size());
            num = atoi(str.c_str());
            ms.insert(num);
            maxPq.push(num);
            minPq.push(num);
        }
        else if (op[2] == '1') {
            if (!ms.empty() && !maxPq.empty())  {
                do{
                    maxNum = maxPq.top();
                    maxPq.pop();
                } 
                while(ms.find(maxNum) == ms.end());
                ms.erase(maxNum);
            }
        }
        else {
            if (!ms.empty() && !minPq.empty()) {
                do {
                minNum = minPq.top();
                minPq.pop();
                }
                while (ms.find(minNum) == ms.end());
                ms.erase(minNum);
            }
        }
    }
    if (ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }
   
    return answer;
}