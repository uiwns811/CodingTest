#include <iostream>
using namespace std;

int arr[1001][3];

int main()
{
	int n;
	cin >> n;

	cin >> arr[1][0] >> arr[1][1] >> arr[1][2];

	int r, g, b;
	for (int i = 2; i <= n; i++) {
		cin >> r >> g >> b;
		arr[i][0] = r + min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] = g + min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] = b + min(arr[i - 1][0], arr[i - 1][1]);
	}

	int result = 1000 * 1000;
	for (int i = 0; i < 3; i++) {
		result = min(result, arr[n][i]);
	}
	cout << result << endl;
}