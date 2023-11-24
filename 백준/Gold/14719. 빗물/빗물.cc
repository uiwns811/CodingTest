#include <iostream>
using namespace std;

int arr[501];

int main()
{
	int h, w;
	cin >> h >> w;

	for (int i = 1; i <= w; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 0;
	int block;
	int result = 0;

	for (int cur = 2; cur < w; cur++) {
		for (int i = 1; i < cur; i++) {
			left = max(left, arr[i]);
		}
		for (int i = cur + 1; i <= w; i++) {
			right = max(right, arr[i]);
		}
		block = min(left, right);
		if (block > arr[cur])
			result += block - arr[cur];
		left = 0;
		right = 0;
	}

	cout << result << endl;
}