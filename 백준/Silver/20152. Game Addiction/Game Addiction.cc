#include <iostream>
#include <memory.h>
using namespace std;

long long dp[31][31] = { 0, };

int main()
{
	int start, end;
	cin >> start >> end;

	int result = 0;

	if (start == end) {
		cout << 1 << endl;
		return 0;
	}
	if (start > end) {
		int temp = end;
		end = start;
		start = temp;
	}

	dp[start][start] = 1;
	for (int i = start + 1; i <= end; i++) {
		dp[i][start] = 1;
		for (int j = start + 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	cout << dp[end][end] << endl;
}