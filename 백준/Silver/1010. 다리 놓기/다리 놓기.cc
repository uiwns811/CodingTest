#include <iostream>
using namespace std;

int dp[30][30];

int main() 
{
	int T;
	cin >> T;

	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i < 30; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	int n, m;
	for (int t = 0; t < T; t++) {
		cin >> n >> m;
		cout << dp[m][n] << endl;
	}
}