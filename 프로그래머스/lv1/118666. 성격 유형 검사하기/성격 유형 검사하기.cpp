#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<char, int> um;

void InitializeMap()
{
    um['R'] = 0;
    um['T'] = 0;
    um['C'] = 0;
    um['F'] = 0;
    um['J'] = 0;
    um['M'] = 0;
    um['A'] = 0;
    um['N'] = 0;
}

char CompareUm(char a, char b)
{
    if (um[a] == um[b]) {
        return min(a, b);
    }
    else if (um[a] > um[b])
        return a;
    else
        return b;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for (int i = 0 ; i < survey.size() ; i++) {
        int cho = choices[i];
        if (cho == 4) continue;
        else if (cho < 4) {
            um[survey[i][0]] += (4 - cho);
        }
        else {
            um[survey[i][1]] += (cho - 4);
        }
    }
    
    answer += CompareUm('R', 'T');
    answer += CompareUm('C', 'F');
    answer += CompareUm('J', 'M');
    answer += CompareUm('A', 'N');
    
    return answer;
}