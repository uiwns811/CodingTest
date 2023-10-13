#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	
	vector<int> tips;

	int tip;
	for (int i = 0; i < n; i++) {
		cin >> tip;
		tips.emplace_back(tip);
	}

	sort(tips.begin(), tips.end(), greater<int>());

	ll result = 0;
	for (int i = 0; i < n; i++) {
		if (tips[i] - i > 0)
			result += (tips[i] - i);
	}

	cout << result;
}