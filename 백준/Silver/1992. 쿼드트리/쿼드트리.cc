#include <iostream>
#include <string>
#include <vector>
using namespace std;

string result = "";
char v[65][65];

void Divide(int x, int y, int size)
{
	int divide = false;
	char first = v[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (v[i][j] != first) {
				result += "(";
				Divide(x, y, size / 2);
				Divide(x, y + size / 2, size / 2);
				Divide(x + size / 2, y, size / 2);
				Divide(x + size / 2, y + size / 2, size / 2);
				result += ")";
				return;
			}
		}
	}
	result += first;
}

int main()
{
	int N;
	cin >> N;

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			v[i][j] = input[j];
		}
	}

	Divide(0, 0, N);

	cout << result << endl;
}