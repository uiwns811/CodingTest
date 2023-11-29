#include <iostream>
using namespace std;

int arr[100'001];
int n, m;

int GetBlueray(int size)
{
	int sum = 0;
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] <= size)
			sum += arr[i];
		else {
			result++;
			sum = arr[i];
		}
	}
	if (sum > 0) result++;
	return result;
}

int main()
{
	cin >> n >> m;

	int total = 0;
	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
		maxValue = max(maxValue, arr[i]);
	}

	int left = maxValue;
	int right = total;
	int mid = 0;
	int answer = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int curCnt = GetBlueray(mid);
		if (curCnt <= m) {
			right = mid - 1;
			answer = mid;
		}
		else left = mid + 1;
	}
	cout << answer << endl;
}