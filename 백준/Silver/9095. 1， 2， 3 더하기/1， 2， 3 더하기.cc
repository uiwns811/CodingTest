#include <iostream>
using namespace std;

int arr[11];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 11; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	for (int tk = 0; tk < t; tk++) {
		int n;
		cin >> n;
		cout << arr[n] << endl;
	}
}