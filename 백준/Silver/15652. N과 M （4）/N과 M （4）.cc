#include <iostream>
#include <vector>
using namespace std;

int arr[9];

void Print(vector<int>& v)
{
	for (int& n : v)
		cout << n << " ";
	cout << "\n";
}

void nHr(int n, int r, int depth, vector<int>& v)
{
	if (depth == r) {
		Print(v);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (depth > 0 && v[depth - 1] > i) continue;
		v[depth] = i;
		nHr(n, r, depth + 1, v);
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<int> vec;
	for (int i = 0; i < m; i++)
		vec.emplace_back(-1);

	nHr(n, m, 0, vec);
}