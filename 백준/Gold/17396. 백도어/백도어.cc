#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

struct compare {
	bool operator() (const pair<int, ll>& a, const pair<int, ll>& b) const {
		return a.second > b.second;
	}
};

ll INF = 10'000'000'000'000;

int n, m;
bool visitable[100'001];
ll cost[100'001];
// idx, cost
vector<pair<int, ll>> vec[100'001];
priority_queue<pair<int, ll>, vector<pair<int, ll>>, compare> pq;

void Dijkstra()
{
	pq.push(make_pair(0, 0));
	cost[0] = 0;
	while (!pq.empty()) {
		int cur = pq.top().first;
		ll curCost = pq.top().second;
		pq.pop();
		if (cur == n - 1) break;
		if (curCost > cost[cur]) continue;
		
		for (auto& v : vec[cur]) {
			int next = v.first;
			ll nextCost = curCost + v.second;
			// if (cost[next] < nextCost) continue;
			if (nextCost < cost[next]) {
				cost[next] = nextCost;
				pq.push(make_pair(next, nextCost));
			}
		}
	}
	if (cost[n - 1] == INF) cout << -1 << '\n';
	else cout << cost[n - 1] << '\n';
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> visitable[i];
		cost[i] = INF;
	}

	int a, b, t;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		//if ((visitable[a] && a != n-1) || (visitable[b] && b != n-1)) continue;
		if ((!visitable[a] && !visitable[b]) || (a == n - 1 || b == n - 1)) {
			vec[a].emplace_back(make_pair(b, t));
			vec[b].emplace_back(make_pair(a, t));
		}
	}

	Dijkstra();
}