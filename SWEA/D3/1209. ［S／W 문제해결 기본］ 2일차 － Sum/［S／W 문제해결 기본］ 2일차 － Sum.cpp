#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    
	for(test_case = 1; test_case <= T; ++test_case)
    {
		int t;
		cin >> t;

		int sum[2][100] = {0, };
		int diag[2] = {0, };
		int result = 0;

		int input;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> input;
				sum[0][i] += input;
				sum[1][j] += input;
				if (i == j) diag[0] += input;
				if (i + j == 99) diag[1] += input;
			}
		}

		for (int i = 0; i < 100; i++) {
			result = max(result, max(sum[0][i], sum[1][i]));
		}
		result = max(result, max(diag[0], diag[1]));

		cout << '#' << t << " " << result << endl;
	}
	return 0;
}