#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	unordered_map<int, string> umId;
	unordered_map<string, int> umName;
	
	string name;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		umId[i] = name;
		umName[name] = i;
	}

	string input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (isalpha(input[0])) {
			cout << umName[input] << '\n';
		}
		else
			cout << umId[stoi(input)] << '\n';
	}
}