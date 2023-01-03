#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<vector<int>> arrs;

	for (int i = 0; i < T; ++i) {
		vector<int> arr;
		int num;
		for (int j = 0; j < 10; ++j) {
			cin >> num;
			arr.emplace_back(num);
		}
		sort(arr.begin(), arr.end());
		arrs.emplace_back(arr);
	}

	for (int i = 0; i < T; ++i) {
			cout << arrs[i][7] << endl;
	}
}