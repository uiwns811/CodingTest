#include <iostream>
#include <limits.h>
using namespace std;

typedef long long ll;
ll arr[10][2];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	ll result = LLONG_MAX;
	for (int i = 0; i < (1 << n); i++) {
		ll s = 1;
		ll b = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				s *= arr[j][0];
				b += arr[j][1];
			}
		}
		if (s == 1 && b == 0) continue;
		result = min(result, abs(s - b));
	}
	cout << result << endl;
}