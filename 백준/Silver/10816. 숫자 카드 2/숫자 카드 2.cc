#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n;

	unordered_map<int, int> um;
	
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		um[input]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		cout << um[input] << " ";
	}

}