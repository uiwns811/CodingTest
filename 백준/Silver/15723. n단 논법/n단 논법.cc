#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> vec;
bool flag = false;

void DFS(int s, int e)
{
	for (int& v : vec[s]) {
		if (v == e) {
			flag = true;
			return;
		}
		DFS(v, e);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
		vec.emplace_back(vector<int>());

	string input;
	int start, end = 0;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		input = "";
		getline(cin, input);
		start = input.c_str()[0] - 'a';
		end = input.c_str()[5] - 'a';

		vec[start].push_back(end);
	}

	int m;
	cin >> m;

	string result = "";
	cin.ignore();
	for (int i = 0; i < m; i++) {
		result = "";
		getline(cin, result);
		start = result.c_str()[0] - 'a';
		end = result.c_str()[5] - 'a';

		DFS(start, end);
		if (flag) cout << "T" << '\n';
		else cout << "F" << '\n';
		flag = false;
	}
}