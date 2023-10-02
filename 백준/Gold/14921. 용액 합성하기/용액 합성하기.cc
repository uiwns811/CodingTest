#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	int arr[100'001];
	int result = 200'000'100;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = N-1;
	while (left < right) {
		int sum = arr[left] + arr[right];
		result = abs(sum) < abs(result) ? sum : result;
		if (sum > 0) --right;
		else ++left;
	}

	cout << result;
}