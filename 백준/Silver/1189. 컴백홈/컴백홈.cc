#include <iostream>
using namespace std;

int R, C, K;

int result = 0;
bool arr[6][6] = { false, };
bool visited[6][6] = { false, };

void DFS(int x, int y, int cnt)
{
	if (x == R && y == C && cnt == K) {
		result++;
		return;
	}
	if (!visited[x + 1][y] && arr[x + 1][y] && x + 1 <= R) {
		visited[x + 1][y] = true;
		DFS(x + 1, y, cnt + 1);
		visited[x + 1][y] = false;
	}
	if (!visited[x - 1][y] && arr[x - 1][y] && x - 1 > 0) {
		visited[x - 1][y] = true;
		DFS(x - 1, y, cnt + 1);
		visited[x - 1][y] = false;
	}
	if (!visited[x][y + 1] && arr[x][y + 1] && y + 1 <= C) {
		visited[x][y + 1] = true;
		DFS(x, y + 1, cnt + 1);
		visited[x][y + 1] = false;
	}
	if (!visited[x][y - 1] && arr[x][y - 1] && y - 1 > 0) {
		visited[x][y - 1] = true;
		DFS(x, y - 1, cnt + 1);
		visited[x][y - 1] = false;
	}
}

int main()
{
	cin >> R >> C >> K;

	string input;
	for (int i = R; i > 0; i--) {
		cin >> input;
		for (int j = 1; j <= C; j++) {
			if (input[j-1] == '.') arr[i][j] = true;
			else arr[i][j] = false;
		}
	}

	visited[1][1] = true;
	DFS(1, 1, 1);
	cout << result << endl;
}