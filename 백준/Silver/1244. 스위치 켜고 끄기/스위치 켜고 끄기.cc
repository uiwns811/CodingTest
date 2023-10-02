#include <iostream>
#include <memory.h>
using namespace std;

unsigned int arr[101];

void Not(unsigned int& n)
{
	if (n == 0) n = 1;
	else n = 0;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	memset(arr, -1, sizeof(arr));

	int s;
	cin >> s;

	for (int i = 1; i <= s; i++) {
		cin >> arr[i];
	}

	int students;
	cin >> students;

	int gender, n;
	for (int student = 0; student < students; student++) {
		cin >> gender >> n;

		if (gender == 1) {
			for (int i = n; i <= s; i += n) {
				Not(arr[i]);
			}
		}
		else {
			int i = 1;
			while (n - i >= 1 && n + i <= s) {
				if (arr[n - i] == arr[n + i]) {
					i++;
				}
				else break;
			}
			Not(arr[n]);
			for (int j = 1; j < i; j++) {
				Not(arr[n - j]);
				Not(arr[n + j]);
			}
		}
	}

	for (int i = 1; i <= s; i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << '\n';
	}
	cout << '\n';
}