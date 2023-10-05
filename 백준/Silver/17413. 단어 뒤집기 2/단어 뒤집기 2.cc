#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	getline(cin, input);

	string result;
	string temp;
	bool isTag = false;

	for (auto& c : input) {
		if (c == '<') {
			reverse(temp.begin(), temp.end());
			result += temp;
			temp = "";

			isTag = true;
			result += c;
		}
		else if (c == '>') {
			isTag = false;
			result += c;
		}
		else if (c == ' ') {
			reverse(temp.begin(), temp.end());
			result += temp;
			temp = "";

			result += c;
		}
		else if (isTag) 
			result += c;
		else
			temp += c;
	}
	reverse(temp.begin(), temp.end());
	result += temp;

	cout << result << endl;
}