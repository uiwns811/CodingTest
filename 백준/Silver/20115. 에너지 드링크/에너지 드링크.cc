#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	double num;
	vector<double> vec;
	double start = 1;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
		start = max(start, num);
	}

	double answer = 0;
	answer += start/2;
	
	for (auto& v : vec) {
		answer += v / 2;
	}
	cout << answer << endl;
}