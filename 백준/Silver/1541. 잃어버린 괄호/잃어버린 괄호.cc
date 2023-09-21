#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string input;
	cin >> input;

	int answer = 0;
	int num = 0;
	string temp = "";
	bool isMinus = false;
	for (int i = 0; i < input.size(); i++) {
		if (isdigit(input[i])) {
			temp += input[i];
		}
		else {
			num = stoi(temp);
			if (!isMinus) answer += num;
			else answer -= num;

			if (input[i] == '-') isMinus = true;

			temp = "";
			num = 0;
		}
	}
	num = stoi(temp);
	if (!isMinus) answer += num;
	else answer -= num;
	cout << answer << endl;
}