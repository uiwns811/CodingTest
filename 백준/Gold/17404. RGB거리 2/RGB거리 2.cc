#include <iostream>
using namespace std;

int arr[1001][3];
int dp[1001][3];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	int result = 1000 * n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int start = 0; start < 3; start++) {
		for (int j = 0; j < 3; j++) {
			if (j == start) dp[1][j] = arr[1][j];
			else dp[1][j] = 1000 * n;
		}
		for (int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}
		for (int j = 0; j < 3; j++) {
			if (j == start) continue;
			result = min(result, dp[n][j]);
		}
	}

	cout << result << '\n';
}