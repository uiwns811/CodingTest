#include <iostream>
#include <string>
using namespace std;

int arr[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int dp[4010][4010];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string a;
	string b;
	cin >> a;
	cin >> b;
	
	for (int i = 0; i < a.size(); i++) {
		int idxA = a[i] - 'A';
		int idxB = b[i] - 'A';
		dp[0][i * 2] = arr[idxA];
		dp[0][i * 2 + 1] = arr[idxB];
	}

	int cnt = a.size() * 2;
	for (int idx = 0 ; idx < cnt - 2 ; idx++) {
		for (int i = 0; i < cnt - 1; i++) 
			dp[idx + 1][i] = (dp[idx][i] + dp[idx][i + 1]) % 10;
	}
	string result = "";
	result += dp[cnt - 2][0] + '0';
	result += dp[cnt - 2][1] + '0';

	cout << result << endl;
}