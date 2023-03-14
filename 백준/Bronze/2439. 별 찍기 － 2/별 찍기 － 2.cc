#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int cnt = 0; cnt < (N - i - 1); cnt++) {
			cout << " ";
		}
		for (int cnt = (N - i - 1); cnt < N; cnt++) {
			cout << "*";
		}
		cout << endl;
	}
}