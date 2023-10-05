#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector<bitset<20>> vec;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		vec.emplace_back(bitset<20>());

	int order, i, x;
	for (int o = 0; o < m; o++) {
		cin >> order >> i;
		if (order == 1) {
			cin >> x;
			vec[i][20 - x] = 1;
		}
		else if (order == 2) {
			cin >> x;
			vec[i][20 - x] = 0;
		}
		else if (order == 3) vec[i] >>= 1;
		else if (order == 4) vec[i] <<= 1;
	}

	vector<bitset<20>> result;
	for (int i = 1; i <= n; i++) {
		bool isSame = false;
		for (auto& r : result) {
			bitset<20> bs = r & vec[i];
			if (bs == r && bs == vec[i]) {
				isSame = true;
				break;
			}
		}
		if (!isSame) result.emplace_back(vec[i]);
	}
	cout << result.size() << endl;
}