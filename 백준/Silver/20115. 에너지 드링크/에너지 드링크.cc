#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	double num;
	vector<double> v;
	double start = 1;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
		start = max(start, num);
	}

	double answer = 0;
	answer += start/2;
	
	for (int i = 0; i < v.size(); i++) {
		answer += v[i] / 2;
	}
	cout << answer << endl;
}