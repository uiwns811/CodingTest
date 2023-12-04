#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	ll x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > 0) pq.push(x);
		else {
			if (pq.empty()) {
				cout << 0 << '\n';
				continue;
			}
			int cur = pq.top();
			cout << cur << '\n';
			pq.pop();
		}
	}
}