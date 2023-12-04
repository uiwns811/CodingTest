#include <iostream>
#include <queue>
using namespace std;

int n, k;
int cost[100'001];
bool visited[100'001];

void Check()
{
	queue<int> q;

	visited[n] = true;
	q.push(n);
	cost[n] = 0;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur - 1 >= 0 && cur - 1 <= 100'000 && !visited[cur - 1]) {
			q.push(cur - 1);
			visited[cur - 1] = true;
			cost[cur - 1] = cost[cur] + 1;
		}
		if (cur + 1 >= 0 && cur + 1 <= 100'000 && !visited[cur + 1]) {
			q.push(cur + 1);
			visited[cur + 1] = true;
			cost[cur + 1] = cost[cur] + 1;
		}
		if (cur * 2 >= 0 && cur * 2 <= 100'000 && !visited[cur * 2]) {
			q.push(cur * 2);
			visited[cur * 2] = true;
			cost[cur * 2] = cost[cur] + 1;
		}
	}
}

int main()
{
	cin >> n >> k;

	Check();
	cout << cost[k] << endl;
}