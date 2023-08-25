#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int x = 0.5 * ((0.5*brown + 2) + sqrt(pow((0.5*brown + 2), 2) - 4 * (yellow + brown)));
    int y = -x + 0.5 * brown + 2;
    
    answer.push_back(x);
    answer.push_back(y);
    
    
    return answer;
}