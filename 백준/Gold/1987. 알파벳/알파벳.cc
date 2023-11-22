#include <iostream>
#include <string>
using namespace std;

int R, C;
char arr[21][21];
bool visited[26] = { false, };
int result = 0;
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

void DFS(int x, int y, int cnt)
{
	result = max(result, cnt);

	for (int i = 0; i < 4; i++) {
		int nextX = x + dir[0][i];
		int nextY = y + dir[1][i];

		if (nextX < 1 || nextY < 1 || nextX > R || nextY > C) continue;
		if (visited[arr[nextX][nextY] - 'A']) continue;
		visited[arr[nextX][nextY] - 'A'] = true;
		DFS(nextX, nextY, cnt + 1);
		visited[arr[nextX][nextY] - 'A'] = false;
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> R >> C;

	string input;
	for (int i = 1; i <= R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			arr[i][j + 1] = input[j];
		}
	}

	visited[arr[1][1] - 'A'] = true;
	DFS(1, 1, 1);

	cout << result << endl;
}