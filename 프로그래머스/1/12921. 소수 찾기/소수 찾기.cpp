#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    std::vector<bool> vec(n+1, true);
    
    for (int tgt = 2 ; tgt <= n ; ++tgt)
    {
        // 이미 특정 숫자의 배수이므로, 검사하지 않습니다.
        if (false == vec[tgt]) continue;
        
        // 아래 연산을 하는 순간, 소수로 가정하고 결과값을 1 증가시켜줍니다.
        ++answer;
        
        // 해당 숫자로 나누어 떨어지는 숫자들을 false로 변경합니다.
        for (int loop{tgt * 2} ; loop <= n ; loop += tgt)
        {
            if (0 == loop % tgt)
                vec[loop] = false;
        }
    }
    return answer;
}