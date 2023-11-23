#include <iostream>
#include <cmath>
#include <vector>
#include <memory.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int result = 0;
	if (n < 4) {
		cout << n << endl;
		return 0;
	}

	int dp[100'001];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	vector<int> vec;
	vec.push_back(1);

	int temp = 987654321;
	for (int i = 4; i <= n; i++) {
		if (sqrt(i) - (int)sqrt(i) == 0) {
			dp[i] = 1;
			vec.push_back(i);
		}
		else {
			for (int j = vec.size() - 1; j >= 0; j--) {
				temp = min(temp, dp[vec[j]] + dp[i - vec[j]]);
			}
			dp[i] = temp;
		}
		temp = 987654321;
	}

	cout << dp[n] << endl;
}