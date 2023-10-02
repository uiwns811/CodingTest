#include <iostream>
#include <vector>
using namespace std;

int N, M;
int result;
vector<vector<int>> vec;
bool visited[1001] = { false, };

void DFS(int n)
{
	visited[n] = true;
	for (int i = 0; i < vec[n].size(); i++) {
		if (visited[vec[n][i]]) continue;
		DFS(vec[n][i]);
	}
}

int main()
{
	cin >> N >> M;
	result = 0;

	for (int i = 0 ; i <= N ; i++)	
		vec.emplace_back(vector<int>());

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			result++;
		}
	}
	cout << result << endl;
}