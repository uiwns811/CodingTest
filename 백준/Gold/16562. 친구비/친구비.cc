#include <iostream>
#include <vector>
using namespace std;

int arr[10001];
vector<vector<int>> vec;
bool visited[10001] = { false, };
int tempCost = 987654321;
int cost = 0;

void DFS(int cur)
{
	visited[cur] = true;
	tempCost = min(tempCost, arr[cur]);
	for (int i = 0; i < vec[cur].size(); i++) {
		if (!visited[vec[cur][i]]) DFS(vec[cur][i]);
	}
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) 
		cin >> arr[i];

	for (int i = 0; i <= n; i++)
		vec.emplace_back(vector<int>());

	int v, w;
	for (int i = 0; i < m; i++) {
		cin >> v >> w;
		vec[v].emplace_back(w);
		vec[w].emplace_back(v);
	}

	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i);
			cost += tempCost;
			tempCost = 987654321;
		}
	}

	if (cost <= k) cout << cost << endl;
	else cout << "Oh no" << endl;
}