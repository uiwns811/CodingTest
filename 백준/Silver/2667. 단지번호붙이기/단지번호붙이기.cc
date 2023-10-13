#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int arr[30][30];
bool visited[30][30];
vector<int> result;
int cnt = 0;

void DFS(int x, int y)
{
	cnt++;
	visited[x][y] = true;
	if (visited[x + 1][y] && visited[x - 1][y] && visited[x][y - 1] && visited[x][y + 1]) {
		return;
	}

	if (!visited[x + 1][y]) DFS(x + 1, y);
	if (!visited[x - 1][y]) DFS(x - 1, y);
	if (!visited[x][y - 1]) DFS(x, y - 1);
	if (!visited[x][y + 1]) DFS(x, y + 1);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	memset(visited, true, sizeof(visited));

	string input;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		for (int j = 1; j <= input.size(); j++) {
			arr[i][j] = input[j-1] - '0';
			if (arr[i][j] == 1) 
				visited[i][j] = false;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				cnt = 0;
				DFS(i, j);
				result.emplace_back(cnt);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int& r : result) cout << r << '\n';
}