#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int K, N;
	cin >> N >> K;

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	
	cout << "<";

	while (q.size() > 1) {
		for (int i = 0; i < K - 1; i++) {
			int n = q.front();
			q.pop();
			q.push(n);
		}
		cout << q.front() << ", ";
		q.pop();
	}

	cout << q.front() << ">";
}