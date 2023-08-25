#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int light = 0;
    int heavy = people.size() - 1;
    
    while(light <= heavy) {
        if (people[light] + people[heavy] <= limit) {
            light++;
        }
        answer++;
        heavy--;
    }
  
    return answer;
}