#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int key;
	int sum = 0;
	vector<int> keys;
	for (int i = 0; i < 9; ++i) {
		cin >> key;
		keys.emplace_back(key);
		sum += key;
	}

	for (int i = 0 ; i < 9 ; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (i == j) continue;
			int test = sum;
			test -= keys[i];
			test -= keys[j];
			if (test == 100) {
				keys.erase(keys.begin() + i);
				keys.erase(keys.begin() + j - 1);
				
				sort(keys.begin(), keys.end());
				for (int k = 0; k < 7; ++k) {
					cout << keys[k] << endl;
				}
				return 0;
			}
		}
	}
}