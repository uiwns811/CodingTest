#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSosu(int a)
{
	if (a == 1) return false;
	for (int i = 2; i < a; ++i) {
		if (a % i == 0) return false;
	}
	return true;
}

int main()
{
	int M, N;
	cin >> M;
	cin >> N;

	int sum = 0;
	int min = N;
	int error = -1;
	
	for (int i = M; i <= N; ++i) {
		if (isSosu(i) == true) {
			sum += i;
			if (min > i) min = i;
		}
	}

	if (sum == 0) {
		cout << error;
	}
	else {
		cout << sum << endl;
		cout << min;
	}
}