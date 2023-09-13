#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		multiset<int> ms;
		
		int k;
		cin >> k;

		for (int j = 0; j < k; j++) {
			char order;
			int n;
			cin >> order >> n;

			if (order == 'I') ms.insert(n);
			else if (ms.empty()) continue;
			else if (n == 1) ms.erase(--ms.end());
			else if (n == -1) ms.erase(ms.begin());
		}
		if (ms.empty()) cout << "EMPTY\n";
		else cout << *--ms.end() << " " << *ms.begin() << '\n';
	}
}