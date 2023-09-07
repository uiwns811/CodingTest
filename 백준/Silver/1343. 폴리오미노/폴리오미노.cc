#include <iostream>
using namespace std;

int main()
{
	string input;
	string answer;
	cin >> input;

	int cnt = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'X') {
			cnt++;
		}
		else {
			answer += ".";
			if (cnt % 2 != 0) {
				answer = "-1";
				break;
			}
			else cnt = 0;
		}
		if (cnt == 2 && input[i + 1] != 'X') {
			answer += "BB";
			cnt = 0;
		}
		if (cnt == 4) {
			answer += "AAAA";
			cnt = 0;
		}
	}
	if (cnt % 2 == 0) cout << answer << "\n";
	else cout << -1 << '\n';
}