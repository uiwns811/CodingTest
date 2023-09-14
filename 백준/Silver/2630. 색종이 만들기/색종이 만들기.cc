#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int arr[128][128];
int N = 0;
int white = 0;
int blue = 0;

void Divide(int x, int y, int size) 
{
	bool cut = false;
	int first = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != first) {
				cut = true;
				break;
			}
		}
	}
	if (cut) {
		Divide(x, y, size/2);
		Divide(x, y + size / 2, size / 2);
		Divide(x + size / 2, y, size / 2);
		Divide(x + size / 2, y + size / 2, size / 2);
	}
	else if (first == 0) white++;
	else blue++;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	memset(arr, -1, sizeof(arr));

	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	Divide(0, 0, N);

	cout << white << '\n';
	cout << blue << '\n';
}