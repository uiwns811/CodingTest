#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	long long x, y;
	cin >> x >> y;

	long long z = 100 * y / x;
	int result = 0;

	if (z >= 99) {
		result = -1;
		cout << result << endl;
		return 0;
	}

	int low = 0;
	int high = 1'000'000'000;
	int mid, target;
	while (low <= high) {
		mid = (low + high) / 2;
		target = 100 * (y + mid) / (x + mid);
		if (z < target) high = mid - 1;
		else low = mid + 1;
	}
	result = low;

	cout << result << endl;
}