#include <iostream>
using namespace std;

int arr[1001];

int main()
{
	int n;
	cin >> n;

	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0)
			arr[i] = (arr[i - 1] * 2 + 1) % 10007;
		else
			arr[i] = (arr[i - 1] * 2 - 1) % 10007;
	}
	cout << arr[n] << endl;
}