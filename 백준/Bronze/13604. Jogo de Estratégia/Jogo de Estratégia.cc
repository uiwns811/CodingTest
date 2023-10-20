#include <iostream>
using namespace std;

int player[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int j, r;
	cin >> j >> r;

	int num;
	for (int i = 0; i < r; i++) {
		for (int p = 1; p <= j; p++) {
			cin >> num;
			player[p] += num;
		}
	}

	int max = 0;
	int result = 0;
	for (int i = 1; i <= j; i++) {
		if (player[i] >= max) {
			max = player[i];
			result = i;
		}
	}
	cout << result << endl;
}