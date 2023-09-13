#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string input;
	string requested;
	string result;

	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) result += input[i];
	}

	cin >> requested;

	if (result.find(requested) == string::npos) cout << 0 << '\n';
	else cout << 1 << '\n';
}