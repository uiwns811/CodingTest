#include "iostream"
#include "vector"
using namespace std;

int main()
{
	int N{}, K{};
	cin >> N >> K;

	vector<int> divisor;

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			divisor.emplace_back(i);
		}
	}


	if (divisor.size() < K)
		cout << 0 << endl;
	else {
		cout << divisor[K - 1] << endl;
	}
}