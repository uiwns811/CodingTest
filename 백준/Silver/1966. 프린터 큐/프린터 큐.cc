#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
		vector<int> v;
		
		for (int j = 0; j < N; j++) {
			cin >> priority;
			if (j == M) q.push(make_pair(priority, true));
			else q.push(make_pair(priority, false));
			v.emplace_back(priority);
		}

		sort(v.begin(), v.end());

		int answer = 0;
		while (!q.empty()) {
			int max = v.back();
			while (q.front().first < max) {
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
				v.pop_back();
				answer++;
			}
		}
		cout << answer << '\n';
	}
}