#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetGCD(int a, int b)
{
	if (a % b == 0) return b;
	else return GetGCD(b, a % b);
}

int GetLCM(int a, int b)
{
	return (a * b) / GetGCD(a, b);
}

int main()
{
	int a, b;
	cin >> a >> b;

	cout << GetGCD(a, b) << endl;
	cout << GetLCM(a, b);
}