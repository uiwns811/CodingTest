#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int answer = 0;
	int five = n / 5;
	int two = 0;
	int cur = n;

	if (n % 2 == 0) {
		answer = n / 2;
	}
	
	while (five > 0) {
		cur = n - five * 5;
		if (cur % 2 == 0) {
			two = cur / 2;
			answer = five + two;
			break;
		}
		else {
			five -= 1;
		}
	}

	if (answer == 0) answer = -1;
	
	cout << answer << '\n';
}