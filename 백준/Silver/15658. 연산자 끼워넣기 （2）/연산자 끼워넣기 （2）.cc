#include <iostream>
using namespace std;

int N;
int arr[13];
int operators[4];

int maxValue = -2'000'000'000;
int minValue = 2'000'000'000;

void Solution(int idx, int value)
{
	if (idx == N) {
		maxValue = max(value, maxValue);
		minValue = min(value, minValue);
		return;
	}
	if (operators[0] > 0) {
		operators[0]--;
		Solution(idx + 1, value + arr[idx + 1]);
		operators[0]++;
	}
	if (operators[1] > 0) {
		operators[1]--;
		Solution(idx + 1, value - arr[idx + 1]);
		operators[1]++;
	}
	if (operators[2] > 0) {
		operators[2]--;
		Solution(idx + 1, value * arr[idx + 1]);
		operators[2]++;
	}
	if (operators[3] > 0) {
		operators[3]--;
		Solution(idx + 1, value / arr[idx + 1]);
		operators[3]++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 4; i++)
		cin >> operators[i];

	Solution(1, arr[1]);

	cout << maxValue << '\n' << minValue << '\n';
}