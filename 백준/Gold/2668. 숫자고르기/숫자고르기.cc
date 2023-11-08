#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101];
bool visited[101] = { false, };
vector<int> vec;

void DFS(int start, int cur, vector<int> v)
{
	if (visited[cur]) return;
	if (start == arr[cur]) {
		for (int& e : v)
			vec.push_back(e);
		return;
	}
	visited[cur] = true;
	v.push_back(arr[cur]);
	DFS(start, arr[cur], v);
	visited[cur] = false;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			vector<int> v;
			v.push_back(i);
			DFS(i, i, v);
		}
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	cout << vec.size() << endl;
	for (int& e : vec)
		cout << e << endl;
}