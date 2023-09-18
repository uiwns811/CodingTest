#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	bool isSk = false;
	while (n > 0) {
		if (n >= 3) {
			n -= 3;
			isSk = !isSk;
		}
		else if (n >= 1) {
			n -= 1;
			isSk = !isSk;
		}
	}
	if (isSk) cout << "SK" << '\n';
	else cout << "CY" << '\n';
}