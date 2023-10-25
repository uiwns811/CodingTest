#include <iostream>
using namespace std;

// 중요도, 시간
int arr[1001][2];
int dp[1001][10001] = { 0, };
int N, K;

void Select()
{
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][1] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i - 1][j], arr[i][0] + dp[i - 1][j - arr[i][1]]);
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> K;
	
	for (int i = 1; i <= K; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	Select();

	cout << dp[K][N];
}