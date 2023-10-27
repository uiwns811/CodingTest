#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
	int n;
	cin >> n;

	vector<int> vec;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		vec.push_back(input);
	}

	int height = 0;
	int left = 0;
	int right = 0;
	for (auto& v : vec) {
		if (v > height) {
			height = v;
			left++;
		}
	}

	height = 0;
	for (auto iter = vec.rbegin(); iter != vec.rend(); iter++) {
		if (*iter > height) {
			height = *iter;
			right++;
		}
	}
	cout << left << endl;
	cout << right << endl;
}