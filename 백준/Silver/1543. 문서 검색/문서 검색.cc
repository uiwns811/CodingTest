#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	string search;
	getline(cin, search);

	int lgth = search.length();

	int answer = 0;
	while (!str.empty()) {
		auto iter = str.find(search);
		if (iter == string::npos) break;
		str = str.substr(iter + lgth, str.size() - iter - lgth + 1);
		answer++;
	}
	cout << answer;
}