#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer(arr);
    vector<int> temp(arr);
    
    int min = 0;
    sort(temp.begin(), temp.end());
    min = temp[0];
    
    auto iter = find(answer.begin(), answer.end(), min);
    answer.erase(iter);
    
    if (answer.empty()) answer.emplace_back(-1);
    
    return answer;
}