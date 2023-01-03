#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<int> result;

	for (int i = 0; i < T; ++i) {
		int arr[10];
		for (int j = 0; j < 10; ++j) {
			cin >> arr[j];
		}
		sort(arr, arr+10);
		result.emplace_back(arr[7]);
	}

	for (int i = 0; i < T; ++i) {
		cout << result[i] << endl;
	}
}