#include <iostream>
#include <string>
using namespace std;

string pattern1;
string pattern2;

bool Check(string input)
{
	if (input.size() < pattern1.size() + pattern2.size())
		return false;
	string s1 = input.substr(0, pattern1.size());
	if (s1 != pattern1)
		return false;
	string s2 = input.substr(input.size() - pattern2.size(), pattern2.size());
	if (s2 != pattern2) 
		return false;
	return true;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	string pattern;
	cin >> pattern;
	pattern1 = pattern.substr(0, pattern.find('*'));
	pattern2 = pattern.substr(pattern.find('*')+1, pattern.length());

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (Check(input)) cout << "DA" << '\n';
		else cout << "NE" << '\n';
	}
}