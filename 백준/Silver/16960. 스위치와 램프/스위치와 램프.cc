#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

// lamp에 연결된 switch들을 담은 벡터
vector<vector<int>> vec;
int n, m;
bool visited[2001] = { false, };
int check = 0;

void Input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		vec.emplace_back();

	int lamps = 0;
	int cur = 0;

	for (int i = 0; i < n; i++) {
		cin >> lamps;
		if (lamps != 0) {
			for (int j = 0; j < lamps; j++) {
				cin >> cur;
				vec[i].push_back(cur);
			}
		}
	}
}

bool CheckSwitch()
{
	for (int i = 0; i < n; i++) {
		if (i != check) {
			for (int& v : vec[i]) {
				visited[v] = true;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		if (!visited[i]) return false;
	}
	return true;
}


int main()
{
	Input();

	bool flag = false;
	while (check < n) {
		flag = CheckSwitch();
		if (flag) break;
		memset(visited, false, sizeof(visited));
		check++;
	}
	cout << flag;
}