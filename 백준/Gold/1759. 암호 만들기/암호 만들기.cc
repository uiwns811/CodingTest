#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> vec;
vector<char> result;

bool Check()
{
	int moeum = 0;
	for (auto& r : result) {
		if (r == 'a' || r == 'e' || r == 'i' || r == 'o' || r == 'u')
			moeum++;
	}
	if (moeum >= 1 && L - moeum >= 2) return true;
	return false;
}

void DFS(int cur)
{
	if (result.size() == L) {
		if (Check()) {
			for (auto& r : result)
				cout << r;
			cout << '\n';
		}
		return;
	}

	for (int i = cur; i < C; i++) {
		result.push_back(vec[i]);
		DFS(i+1);
		result.pop_back();
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> L >> C;

	char c;
	for (int i = 0; i < C; i++) {
		cin >> c;
		vec.push_back(c);
	}
	sort(vec.begin(), vec.end());

	DFS(0);
}