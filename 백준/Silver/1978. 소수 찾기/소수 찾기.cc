#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSosu(int a)
{
	if (a == 1) return false;
	else {
		for (int i = 2; i < a; ++i) {
			if (a % i == 0) return false;
		}
		return true;
	}
}

int main()
{
	int T;
	cin >> T;

	int num;
	int result = 0;

	for (int i = 0; i < T; ++i) {
		cin >> num;
		
		if (isSosu(num) == true)
			result++;
	}
	cout << result;
}