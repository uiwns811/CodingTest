#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int arr[100'001];
string name[100'001];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	string str;
	ll maxNum;
	for (int i = 0; i < n; i++) {
		cin >> name[i] >> arr[i];
	}

	ll input;
	for (int i = 0; i < m; i++) {
		cin >> input;

		int left = 0;
		int right = n - 1;
		ll mid = 0;
		string result = "";
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] < input) left = mid + 1;
			else if (arr[mid] >= input) right = mid - 1;
		}
		if (input > arr[mid]) result = name[mid + 1];
		else result = name[mid];
		cout << result << '\n';
	}
}