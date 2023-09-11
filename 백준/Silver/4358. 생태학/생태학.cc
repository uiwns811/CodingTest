#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int total = 0;
	map<string, float> m;

	string input;
	while (getline(cin, input)) {
		total++;
		m[input]++;
	}
	
	cout << fixed;
	cout.precision(4);
	for (auto& tree : m) {
		cout << tree.first << " " << (float)((tree.second / total) * 100) << '\n';
	}
}