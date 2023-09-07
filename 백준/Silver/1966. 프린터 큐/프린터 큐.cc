#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int TestCase, N, M;
	int priority;
	cin >> TestCase;

	for (int i = 0; i < TestCase ; i++) {
		// 각 테스트 케이스
		cin >> N >> M;

		queue<pair<int, bool>> q;
		priority_queue<int> pq;
		
		for (int j = 0; j < N; j++) {
			cin >> priority;
			if (j == M) q.push(make_pair(priority, true));
			else q.push(make_pair(priority, false));
			pq.push(priority);
		}

		int answer = 0;
		while (!q.empty()) {
			while (q.front().first < pq.top()) {
				pair<int, bool> val = q.front();
				q.pop();
				q.push(val);
			}
			if (q.front().second) {
				answer++;
				break;
			}
			else {
				q.pop();
				pq.pop();
				answer++;
			}
		}
		cout << answer << '\n';
	}
}