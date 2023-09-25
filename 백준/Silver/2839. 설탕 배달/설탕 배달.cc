#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int five = n / 5;
	int three = 0;
	int answer = -1;

	while (five >= 0) {
		if ((n - five * 5) % 3 == 0) {
			three = (n - five * 5) / 3;
			answer = three + five;
			break;
		}
		five--;
	}
	cout << answer << endl;
}