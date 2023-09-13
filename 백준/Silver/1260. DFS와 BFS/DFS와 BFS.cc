#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

bool visited[1001]{ false };

void DFS(vector<vector<int>>& v, int idx, int cnt)
{
	if (v.size() - 1 <= cnt) return;
	cout << idx << " ";
	visited[idx] = true;
	sort(v[idx].begin(), v[idx].end());
	for (int i = 0; i < v[idx].size(); i++) {
		if (visited[v[idx][i]]) continue;
		DFS(v, v[idx][i], ++cnt);
	}
}

void BFS(vector<vector<int>>& v, int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int idx = q.front();
		cout << idx << " ";
		q.pop();
		sort(v[idx].begin(), v[idx].end());
		for (auto& n : v[idx]) {
			if (visited[n]) continue;
			q.push(n);
			visited[n] = true;
		}
	}
	cout << '\n';
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<int>> vertex;
	for (int i = 0; i < N + 2; i++) {
		vertex.emplace_back(vector<int>());
	}
	
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		vertex[x].push_back(y);
		vertex[y].push_back(x);
	}

	DFS(vertex, V, 1);
	cout << '\n';

	memset(visited, false, sizeof(visited));

	BFS(vertex, V);
}