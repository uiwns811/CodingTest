#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll n, k;
	cin >> n >> k;

	string result = "NO";

	ll left = 0;
	ll right = n/2;
	ll mid = 0;
	ll midValue = 0;
	
	while (left <= right) {
		mid = (left + right) / 2;
		midValue = (mid + 1) * (n - mid + 1);
		if (midValue > k) right = mid - 1;
		else if (midValue < k) left = mid + 1;
		else {
			result = "YES";
			break;
		}
	}

	cout << result;
}