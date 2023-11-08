#include <iostream>
using namespace std;

int N;
int hp[21];
int joy[21];
int dp[101] = { 0, };
int result;

void Solution()
{
	for (int i = 0; i < N; i++) {
		for (int j = 99; j >= hp[i]; j--) {
			dp[j] = max(dp[j], dp[j - hp[i]] + joy[i]);
			result = max(dp[j], result);
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> hp[i];

	for (int i = 0; i < N; i++)
		cin >> joy[i];
	
	Solution();
	cout << result;
}