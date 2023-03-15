using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long currentPrice = 0;
    
    for (int i = 1 ; i <= count ; i++) {
        currentPrice += price * i;
    }
    
    if (money >= currentPrice)
        answer = 0;
    else 
        answer = currentPrice - money;
    
    
    return answer;
}