#include <iostream>
using namespace std;

int n;
int arr[100'001];
int dp[100'001];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	int result = -1000 * n;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}
	
	cout << result << endl;
}