#include <iostream>
using namespace std;

int arr[100'001];

int main()
{
	int n, k;
	cin >> n >> k;

	int sum = 0;
	for (int i = 1; i <= k; i++) sum += i;

	int result = 0;
	if (sum > n) result = -1;
	else if (sum == n) result = k - 1;
	else {
		if ((n - sum) % k == 0) result = k - 1;
		else result = k;
	}
	cout << result << endl;
}