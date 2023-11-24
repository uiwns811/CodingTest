#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C;
bool map[12][12] = { false, };
bool final[12][12] = { false, };
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

void Solution()
{
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j]) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nextX = i + dir[0][k];
					int nextY = j + dir[1][k];

					if (!map[nextX][nextY])
						cnt++;
				}
				if (cnt < 3)
					final[i][j] = true;
			}
		}
	}
}

int main()
{
	cin >> R >> C;

	string input;
	for (int i = 1; i <= R; i++) {
		cin >> input;
		for (int j = 1; j <= C; j++) {
			if (input[j-1] == 'X')
				map[i][j] = true;
		}
	}

	Solution();

	int startX = R;
	int startY = C;
	int endX = 0;
	int endY = 0;
	bool check = false;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (final[i][j]) {
				startX = min(startX, i);
				startY = min(startY, j);
				endX = max(endX, i);
				endY = max(endY, j);
			}
		}
	}

	for (int i = startX; i <= endX; i++) {
		for (int j = startY; j <= endY; j++) {
			if (final[i][j]) cout << 'X';
			else cout << '.';
		}
		cout << '\n';
	}
}