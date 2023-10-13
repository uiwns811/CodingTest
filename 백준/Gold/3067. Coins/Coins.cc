#include <iostream>
#include <memory.h>
using namespace std;

int coins[21];
int dp[10001];

int main()
{
	int t;
	cin >> t;

	int n, m;
	int result = 0;
	for (int tk = 0; tk < t; tk++) {
		result = 0;
		memset(coins, 0, sizeof(coins));
		memset(dp, 0, sizeof(dp));

		cin >> n;
		
		for (int i = 0; i < n; i++)
			cin >> coins[i];
		cin >> m;

		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = coins[i]; j <= m; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}
		cout << dp[m] << endl;
	}
}