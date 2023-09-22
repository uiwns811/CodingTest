#include <iostream>
using namespace std;

long long GetGCD(long long a, long long b)
{
	if (b == 0) return a;
	return GetGCD(b, a % b);
}

long long  GetLCM(long long a, long long b)
{
	return a * b / GetGCD(a, b);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;

		if (a < b) {
			long long temp = a;
			a = b;
			b = temp;
		}
		
		cout << GetLCM(a, b) << endl;
	}
}