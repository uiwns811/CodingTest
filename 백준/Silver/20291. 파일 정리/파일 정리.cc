#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		auto dot = find(input.begin(), input.end(), '.');
		string str="";
		for (auto iter = dot + 1; iter < input.end(); iter++)
			str += *iter;
		m[str]++;
	}

	for (auto& r : m)
		cout << r.first << " " << r.second << '\n';
}