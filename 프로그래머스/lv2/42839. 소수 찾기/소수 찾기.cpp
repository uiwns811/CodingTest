#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    vector<int> subset;
    
    // 숫자들의 전체 조합 찾기
    sort(numbers.begin(), numbers.end());
    
    do {
       for(int i = 1 ; i<= numbers.size() ; i++) {
           string num = numbers.substr(0, i);
           subset.emplace_back(atoi(num.c_str()));
       }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    sort(subset.begin(), subset.end());
    subset.erase(unique(subset.begin(), subset.end()), subset.end());
    
    // vec에서 소수 찾기
    
    vector<bool> check;
    for(int i = 0 ; i <= subset[subset.size()-1] ; i++)
        check.emplace_back(false);
    
    check[0] = true;
    check[1] = true;
    
    for(int i = 2 ; i <= subset[subset.size()-1] ; i++) {
        if (check[i]) continue;
        for(int j = 2 * i ; j <= subset[subset.size()-1] ; j += i)
            check[j] = true;
	}
    
    for(auto& v : subset) {
        if (!check[v]) 
           	answer++;
    }
    
    return answer;
}