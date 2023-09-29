#include <iostream>
using namespace std;

int dp[101][100'001] = { 0, };
int arr[101][2];		// 0 : w || 1 : v

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	/*arr[1][0] = 6; arr[1][1] = 13;
	arr[2][0] = 4; arr[2][1] = 8;
	arr[3][0] = 3; arr[3][1] = 6;
	arr[4][0] = 5; arr[4][1] = 12;

	dp[1][1] = dp[0][1] = 0;
	dp[1][6] = 13 + dp[0][0] = 13;
	dp[1][7] = 13 + dp[0][1] = 13;

	dp[2][1] = dp[1][1] = 0;
	dp[2][4] = 8 + dp[1][4 - 4] = 8;
	dp[2][5] = 8 + dp[1][5 - 4] = 8;
	dp[2][6] = 8 + dp[1][6 -4] = 8;
	dp[2][7] = 8 + dp[1][7 - 4] = 8;

	dp[3][1] = dp[2][1] = 0;
	dp[3][3] = 6 + dp[2][3 - 3] = 6;
	dp[3][7] = 6 + dp[2][7 - 3] = 6 + dp[2][4] = 6 + 8 = 14;
	
	dp[4][1] = dp[3][1] = 0;
	dp[4][5] = 12 + dp[3][5 - 5] = 12;
	dp[4][7] = 12 + dp[3][7 - 5] = 12;*/


	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= k; w++) {
			if (arr[i][0] <= w)
				dp[i][w] = max(dp[i - 1][w], arr[i][1] + dp[i - 1][w - arr[i][0]]);
			else
				dp[i][w] = dp[i - 1][w];
		}
	}
	cout << dp[n][k] << endl;
}