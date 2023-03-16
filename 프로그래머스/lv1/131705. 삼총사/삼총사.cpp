#include <string>
#include <vector>

using namespace std;

// number[0]부터 시작해서, 깊이 우선 탐색하면 되지 않을까?

int solution(vector<int> number) {
    int answer = 0;
    
    int size = number.size();
    for (int i = 0 ; i < size - 2; i++) {
        for (int j = i + 1 ; j < size - 1 ; j++) {
            for (int k = j + 1 ; k < size ; k++) {
                if (number[i] + number[j] + number[k] == 0)
                    answer += 1;
            }
        }
    }
    
    return answer;
}