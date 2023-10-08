#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char m[6] = { 'a', 'i', 'y', 'e', 'o', 'u' };
char M[6] = { 'A', 'I', 'Y', 'E', 'O', 'U' };
char j[20] = { 'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f' };

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string input;
	bool isUpper = false;
	while (getline(cin, input)) {
		for (int i = 0; i < input.size(); i++) {
			if (!isalpha(input[i])) continue;
			isUpper = false;
			char c;
			if (isupper(input[i])) {
				isUpper = true;
				input[i] = tolower(input[i]);
			}
			auto iter = find(begin(m), end(m), input[i]);
			if (iter != end(m)) {
				int idx = iter - begin(m);
				input[i] = m[(idx + 3) % 6];
			}
			else {
				auto iter = find(begin(j), end(j), input[i]);
				if (iter != end(j)) {
					int idx = iter - begin(j);
					input[i] = j[(idx + 10) % 20];
				}
			}
			if (isUpper) input[i] = toupper(input[i]);
		}
		cout << input << '\n';
	}
}