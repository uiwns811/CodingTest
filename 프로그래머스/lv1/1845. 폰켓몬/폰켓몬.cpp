#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int n = nums.size();
    int select = n/2;
    
    unordered_set<int> s(nums.begin(), nums.end());
    
    answer = (s.size() < select ? s.size() : select);
    
    return answer;
}