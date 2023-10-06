#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
vector<vector<pair<int, int>>> vec;
int cost[1001];
int start, dest;

void Dijkstra()
{
	pq.push(make_pair(start, 0));
	cost[start] = 0;

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cst = pq.top().second;
		pq.pop();
		if (cst > cost[cur]) continue;

		for (auto& s : vec[cur]) {
			int next = s.first;
			int nextCost = cost[cur] + s.second;
			if (cost[next] > nextCost) {
				cost[next] = nextCost;
				pq.push(make_pair(next, nextCost));
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i <= n; i++) {
		vec.emplace_back(vector<pair<int, int>>());
		cost[i] = 987654321;
	}

	int s, e, c;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		vec[s].emplace_back(make_pair(e, c));
	}

	cin >> start >> dest;

	Dijkstra();

	cout << cost[dest] << endl;
}