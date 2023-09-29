#include <iostream>
#include <algorithm>
using namespace std;

char moeum[5] = { 'a', 'e', 'i', 'o', 'u' };
bool isMoeumIncluded = false;

void CheckIsMoeum(char c, int& m_cont, int& j_cont)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		m_cont++;
		j_cont = 0;
		isMoeumIncluded = true;
	}
	else {
		j_cont++;
		m_cont = 0;
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string input;
	while (cin >> input) {
		if (input == "end") break;
		isMoeumIncluded = false;
		bool isAcceptable = true;

		int m_cont = 0;
		int j_cont = 0;
		CheckIsMoeum(input[0], m_cont, j_cont);
		
		char prev = input[0];
		for (int i = 1; i < input.size(); i++) {
			if (prev == input[i] && prev != 'e' && prev != 'o') {
				isAcceptable = false;
				break;
			}
			prev = input[i];
			CheckIsMoeum(input[i], m_cont, j_cont);
			if (m_cont >= 3 || j_cont >= 3) {
				isAcceptable = false;
				break;
			}
		}
		if (!isMoeumIncluded) isAcceptable = false;

		if (isAcceptable)
			cout << "<" << input << "> is acceptable." << '\n';
		else
			cout << "<" << input << "> is not acceptable." << '\n';
	}
}