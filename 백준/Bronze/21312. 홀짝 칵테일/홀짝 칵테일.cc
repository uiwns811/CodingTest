#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	vector<int> vec;

	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	vec.push_back(a * b);
	vec.push_back(b * c);
	vec.push_back(a * c);
	vec.push_back(a * b * c);

	sort(vec.begin(), vec.end());
	int max = vec.back();
	int result = 0;
	while (!vec.empty()) {
		result = vec.back();
		if (result % 2 != 0) {
			break;
		}
		vec.pop_back();
	}
	if (result % 2 == 0) result = max;

	cout << result << endl;
}