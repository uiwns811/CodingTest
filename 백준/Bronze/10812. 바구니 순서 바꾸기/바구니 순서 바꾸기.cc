#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bucket;

void Show()
{
	for (auto& b : bucket) {
		cout << b << " ";
	}
}


int main()
{
	int N, M;
	int begin, mid, end;
	
	cin >> N >> M;

	bucket.reserve(N * 2);

	for (int n = 1; n <= N; n++) {
		bucket.emplace_back(n);
	}

	for (int ways = 0; ways < M; ++ways) {
		cin >> begin >> end >> mid;

		// begin - 1부터 end(end-1번쨰)까지, mid-1번쨰가  맨 앞에 오도록
		rotate(bucket.begin() + (begin - 1), bucket.begin() + (mid - 1), bucket.begin() + end);
	}
	
	Show();
}