#include <iostream>
using namespace std;

long long arr[100'001];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	arr[0] = 0;
	int input;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		arr[i] = arr[i - 1] + input;
	}

	int start, end;
	long long result = 0;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		cout << arr[end] - arr[start-1] << '\n';
	}
}