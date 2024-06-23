#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;

	multiset<string> mem;
	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		mem.insert(name);
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> name;
		mem.erase(mem.find(name));
	}
	cout << *mem.begin();
}