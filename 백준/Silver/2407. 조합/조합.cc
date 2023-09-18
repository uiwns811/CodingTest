#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[101][101];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) dp[i][j] = "1";
			else {
				string s1 = dp[i - 1][j - 1];
				string s2 = dp[i - 1][j];
				int sum = 0;
				string s3;

				while (!s1.empty() || !s2.empty() || sum) {
					if (!s1.empty()) {
						sum += s1.back() - '0';
						s1.pop_back();
					}
					if (!s2.empty()) {
						sum += s2.back() - '0';
						s2.pop_back();
					}
					s3.push_back((sum % 10) + '0');
					sum /= 10;
				}
				reverse(s3.begin(), s3.end());
				dp[i][j] = s3;
			}
		}
	}
	cout << dp[n][m] << endl;
}