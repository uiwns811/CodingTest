#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[111][111];
bool visited[111][111];
int cost[111][111] = { 0, };
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int answer = 0;

void BFS()
{
	visited[1][1] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	cost[1][1] = 1;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = dir[0][i] + curX;
			int nextY = dir[1][i] + curY;			
			if (visited[nextX][nextY]) continue;
			if (!arr[nextX][nextY]) continue;
			visited[nextX][nextY] = true;
			q.push(make_pair(nextX, nextY));
			cost[nextX][nextY] = cost[curX][curY] + 1;
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	string input;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = input[j - 1] - '0';
		}
	}
	
	BFS();

	cout << cost[n][m] << endl;
}