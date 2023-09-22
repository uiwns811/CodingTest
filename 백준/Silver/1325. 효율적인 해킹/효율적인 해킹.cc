#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> vec[10'001];
bool visited[10'001] = { false, };
int hack[10'001];

bool compare(pair<int, int>& lhs, pair<int, int>& rhs)
{
	if (lhs.second == rhs.second) return lhs.first < rhs.first;
	return lhs.second > rhs.second;
}

int DFS(int n)
{
	int result = 1;
	visited[n] = true;
	if (vec[n].empty()) return 1;
	for (int& vin : vec[n]) {
		if (!visited[vin]) {
			result += DFS(vin);
		}
	}
	return result;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[b].push_back(a);
	}

	vector<pair<int, int>> result;
	int maxHack = -1;
	for (int i = 1; i <= n; i++) {
		int canHack = DFS(i);
		memset(visited, false, sizeof(visited));
		maxHack = max(maxHack, canHack);
		result.emplace_back(make_pair(i, canHack));
	}

	for (auto& r : result) {
		if (r.second == maxHack) cout << r.first << " ";
	}
	//sort(result.begin(), result.end(), compare);

	//int top = result.front().second;
	//for (auto& r : result) {
	//	if (r.second != top) break;
	//	cout << r.first << " ";
	//}
}