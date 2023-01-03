#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[12];
int operators[4];
int min_output = 1000000000;
int max_output = -1000000000;

void GetResult(int num, int idx)
{
	if (idx == N - 1)
	{
		if (num >= max_output) {
			max_output = num;
		}
		if (num <= min_output) {
			min_output = num;
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (operators[i] > 0) {
			operators[i]--;
			switch (i) {
			case 0:
				GetResult(num + arr[idx + 1], idx + 1);
				break;
			case 1:
				GetResult(num - arr[idx + 1], idx + 1);
				break;
			case 2:
				GetResult(num * arr[idx + 1], idx + 1);
				break;
			case 3:
				GetResult(num / arr[idx+1], idx + 1);
				break;
			}
			operators[i]++;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < 4; ++i) {
		cin >> operators[i];
	}

	GetResult(arr[0], 0);
	cout << max_output << endl;
	cout << min_output << endl;
}