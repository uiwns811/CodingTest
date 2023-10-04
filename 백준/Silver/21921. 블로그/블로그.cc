#include <iostream>
using namespace std;

int arr[250'001];

int main()
{
	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int front = 0;
	int rear = 0;
	int visitor = 0;
	int cnt = 0;
	int sum = arr[rear];
	while (front < n && rear <= n - x) {
		if (front - rear == x - 1) {
			if (sum == visitor) ++cnt;
			if (sum > visitor) {
				visitor = sum;
				cnt = 1;
			}
			sum += arr[++front];
		}
		else if (front - rear < x - 1) {
			sum += arr[++front];
		}
		else {
			sum -= arr[rear++];
		}
	}
	
	if (visitor == 0) cout << "SAD" << endl;
	else cout << visitor << endl << cnt << endl;
}