#include <iostream>
using namespace std;

int arr[501][501];
int dp[501][501];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	//dp[1][1] = arr[1][1];

	//dp[2][1] = arr[2][1] + arr[1][1];
	//dp[2][2] = arr[2][2] + arr[1][1];
	//
	//dp[3][1] = arr[3][1] + dp[2][1];
	//dp[3][2] = max(arr[3][2] + dp[2][1], arr[3][2] + dp[2][2]);
	//dp[3][3] = arr[3][3] + dp[2][2];

	//dp[4][1] = arr[4][1] + dp[3][1];
	//dp[4][2] = max(arr[4][2] + dp[3][1], arr[4][2] + dp[3][2]);
	//dp[4][3] = max(arr[4][3] + dp[3][2], arr[4][3] + dp[3][3]);
	//dp[4][4] = arr[4][4] + dp[4][3];


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				dp[i][j] = arr[i][j] + dp[i - 1][j];
			if (j == i)
				dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
			else 
				dp[i][j] = max(arr[i][j] + dp[i - 1][j - 1], arr[i][j] + dp[i - 1][j]);
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, dp[n][i]);
	}
	cout << result << endl;
}