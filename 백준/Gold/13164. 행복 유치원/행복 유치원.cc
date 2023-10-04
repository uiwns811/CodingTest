#include <iostream>
#include <algorithm>
using namespace std;

int arr[300'001];
int cost[300'001];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++)
		cost[i - 1] = arr[i] - arr[i - 1];

	sort(cost, cost + n - 1);

	long long result = 0;
	for (int i = 0; i < n - k; i++)
		result += cost[i];

	cout << result << endl;
}