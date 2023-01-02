#include <iostream>

using namespace std;

int main()
{
	int input;
	cin >> input;

	int num{ 0 };
	if (input < 2) {
		cout << input;
	}
	else {
		int n1 = 0;
		int n2 = 1;
		int cnt = 0;
		while (cnt + 2 <= input) {
			num = n1 + n2;
			n1 = n2;
			n2 = num;
			cnt++;
		}
		cout << num;
	}
}