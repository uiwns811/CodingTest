#include <iostream>
using namespace std;

int arr[21][2];
int dp[21][2];		// [0] : 여기까지 슈점 안쓰고 옴  [1] : 여기까지 슈점쓰고 옴

int main()
{
	int n, k;
	cin >> n;

	for (int i = 1; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	cin >> k;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 5000 * 20;
		dp[i][1] = 5000 * 20;
	}

	dp[1][0] = 0;
	dp[2][0] = arr[1][0];
	dp[3][0] = min(arr[1][0] + arr[2][0], arr[1][1]);

	for (int i = 4; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][0] + arr[i - 1][0], dp[i - 2][0] + arr[i - 2][1]);
		dp[i][1] = min(dp[i-3][0] + k, min(dp[i - 1][1] + arr[i - 1][0], dp[i - 2][1] + arr[i - 2][1]));
	}

	cout << min(dp[n][0], dp[n][1]) << endl;
}