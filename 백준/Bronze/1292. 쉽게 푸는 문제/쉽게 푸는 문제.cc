#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int start, end;
	cin >> start >> end;

	vector<int> arr;

	int sum = 0;
	for (int i = 1; i <= 45; ++i) {
		for (int j = 1; j <= i; ++j) {
			arr.emplace_back(i);
		}
	}
	
	int result = 0;
	for (int i = start; i <= end; ++i) {
		result += arr[i - 1];
	}
	cout << result;
}