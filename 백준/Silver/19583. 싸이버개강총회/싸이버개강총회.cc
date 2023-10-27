#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int GetTime(string time)
{
	return atoi(time.substr(0, 2).c_str()) * 60 + atoi(time.substr(3, 2).c_str());
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string S, E, Q;
	cin >> S >> E >> Q;

	int start_time = GetTime(S);
	int end_time = GetTime(E);
	int check_time = GetTime(Q);

	unordered_set<string> us;
	int result = 0;

	string time, name;
	while (1) {
		cin >> time >> name;
		if (cin.eof()) break;

		int cur_time = GetTime(time);
		if (cur_time > check_time) break;
		

		if (cur_time <= start_time) us.insert(name);
		else if (cur_time >= end_time && cur_time <= check_time) {
			if (us.find(name) != us.end()) {
				result++;
				us.erase(name);
			}
		}
	}
	cout << result << endl;
}