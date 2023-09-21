#include <iostream>
using namespace std;

bool arr[201][201] = {false,};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (arr[i][j]) continue;
			for (int k = j + 1; k <= n; k++) {
				if (arr[i][k]) continue;
				if (arr[j][k]) continue;
				answer++;
			}
		}
	}
	cout << answer << '\n';
}