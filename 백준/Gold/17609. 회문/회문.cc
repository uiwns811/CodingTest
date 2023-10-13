#include <iostream>
#include <string>
using namespace std;

string input;
int flag;

int isPalindrome(int a, int b) 
{
	while (a < b) {
		if (input[a] == input[b]) {
			a++;
			b--;
		}
		else if (flag == 0) {
			flag = 1;
			if (isPalindrome(a + 1, b) == 0 || isPalindrome(a, b - 1) == 0)
				return 1;
		}
		else return 2;
	}
	return 0;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> input;
		flag = 0;
		cout << isPalindrome(0, input.size() - 1) << '\n';
	}
}