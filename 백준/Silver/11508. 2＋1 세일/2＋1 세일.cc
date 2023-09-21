#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int price;
	vector<int> prices;
	for (int i = 0; i < n; i++) {
		cin >> price;
		prices.push_back(price);
	}

	sort(prices.begin(), prices.end(), greater<int>());

	int answer = 0;
	for (int i = 1; i <= prices.size(); i++) {
		if (i % 3 == 0) continue;
		answer += prices[i-1];
	}
	cout << answer << endl;
}