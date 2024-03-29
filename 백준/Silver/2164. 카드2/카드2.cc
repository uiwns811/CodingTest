#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);

	int N;
	cin >> N;

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		int val = q.front();
		q.pop();
		q.push(val);
	}
	cout << q.front() << '\n';
}