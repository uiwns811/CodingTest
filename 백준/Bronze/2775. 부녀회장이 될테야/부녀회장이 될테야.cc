#include <iostream>
using namespace std;

int dp[15][15];

int main()
{
	int T;
	cin >> T;

	dp[1][1] = 1;
	for (int i = 2; i <= 14; i++) {
		for (int j = 1; j <= i; j++)
			dp[1][i] += j;
	}

	for (int i = 2; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			for (int k = 1; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	for (int t = 0; t < T; t++) {
		int k, n;
		cin >> k;
		cin >> n;

		cout << dp[k][n] << endl;
	}
}