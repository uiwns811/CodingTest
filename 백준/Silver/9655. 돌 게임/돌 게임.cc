#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	if (n % 2 != 0) cout << "SK" << '\n';
	else cout << "CY" << '\n';
}