#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<long long> vec;
queue<long long> q;

int main()
{
	long long a, b;
	cin >> a >> b;

	int answer = 0;
	
	q.push(4);
	q.push(7);
	while (!q.empty()) {
		long long cur = q.front();
		if (cur > b)
			break;
		if (cur >= a && cur <= b)
			answer++;
		q.pop();
		q.push(cur * 10 + 4);
		q.push(cur * 10 + 7);
	}
	
	cout << answer << endl;
}