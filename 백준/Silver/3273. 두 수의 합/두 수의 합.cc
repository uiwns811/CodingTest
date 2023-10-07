#include <iostream>
#include <algorithm>
using namespace std;

int arr[100'001];

int main()
{
	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> x;

	sort(arr, arr + n);

	int left = 0;
	int right = n - 1;
	int mid = 0;
	int result = 0;
	while (left < right) {
		mid = arr[left] + arr[right];
		if (mid == x) {
			result++;
			left++;
		}
		else if (mid < x) left++;
		else right--;
	}
	cout << result << endl;
} 