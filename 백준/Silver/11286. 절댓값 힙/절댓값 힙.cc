#include <iostream>
#include <queue>
using namespace std;

struct Compare {
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		if (a.second == b.second) return a.first > b.first;
		else return a.second > b.second;
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int num;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top().first << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(make_pair(num, abs(num)));
		}
	}
}