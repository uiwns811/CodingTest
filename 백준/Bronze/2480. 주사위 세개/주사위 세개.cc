#include <iostream>
using namespace std;

const int Max(const int a, const int b, const int c) 
{
	int f = (a > b ? a : b);
	int result = (f > c ? f : c);
	return result;
}

int main()
{
	int a, b, c;
	int result;
	cin >> a >> b >> c;

	if (a == b && b == c) {
		result = 10000 + a * 1000;
	}
	else if (a == b || a == c) {
		result = 1000 + a * 100;
	}
	else if (b == c) {
		result = 1000 + b * 100;
	}
	else {
		int max = Max(a, b, c);
		result = max * 100;
	}
	
	cout << result;
}
