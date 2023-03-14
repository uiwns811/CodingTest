#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int min = N - 1;
	int max = N - 1;

	for (int i = 0; i < N * 2 - 1; ++i) {
		for (int cnt = 0; cnt < N * 2 - 1; ++cnt) {
			cout << ((cnt >= min && cnt <= max) ? "*" : " ");
			if (cnt > max) break;
		}

		if (i != (N - 1) * 2)
			cout << endl;

		(i < N - 1 ? min-- : min++);
		(i < N - 1 ? max++ : max--);
	}
}