#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

int M, N;
int total = 0;
int arr[1005][1005];
int result = -1;
queue<pair<int, int>> q;
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int cnt = 0;
int temp = 0;
int curCnt = 0;

void BFS()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
				curCnt++;
			}
		}
	}

	while (!q.empty() && cnt <= total) {
		for (int i = 0; i < curCnt; i++) {
			pair<int, int> cur = q.front();
			q.pop();
			cnt++;

			for (int i = 0; i < 4; i++) {
				int nextX = cur.first + dir[0][i];
				int nextY = cur.second + dir[1][i];
				if (arr[nextX][nextY] == 0) {
					q.push(make_pair(nextX, nextY));
					arr[nextX][nextY] = 1;
					temp++;
				}
			}
		}
		result++;
		curCnt = temp;
		temp = 0;
	}
	if (cnt < total) result = -1;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> M >> N;
	total = N * M;

	memset(arr, -1, sizeof(arr));

	int n;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) total--;
		}
	}

	BFS();

	cout << result << endl;
}