#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int korean;
	int english;
	int math;

public:
	Student(string _name, int _korean, int _english, int _math) :
		name(_name), korean(_korean), english(_english), math(_math) {}

	bool operator< (const Student& rhs) const {
		if (this->korean == rhs.korean) {
			if (this->english == rhs.english) {
				if (this->math == rhs.math)
					return this->name < rhs.name;
				else
					return this->math > rhs.math;
			}
			else
				return this->english < rhs.english;
		}
		else
			return this->korean > rhs.korean;
	}

	void Show()
	{
		cout << name << '\n';
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	
	string name;
	int k, e, m;
	vector<Student> vec;

	for (int i = 0; i < n; i++) {
		cin >> name >> k >> e >> m;
		vec.emplace_back(name, k, e, m);
	}

	sort(vec.begin(), vec.end());

	for (auto& v : vec)
		v.Show();
}