#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
vector<int> computers[101];
bool visited[101]{ false };

void dfs(int n)
{
	visited[n] = true;
	for (int i = 0; i < computers[n].size(); i++) {
		int curCom = computers[n][i];
		if (visited[curCom] == false) {
			dfs(computers[n][i]);
			answer++;
		}
	}
}

int main()
{
	int computerCnt = 0;
	int pairNum = 0;
	cin >> computerCnt >> pairNum;

	int num1, num2;
	for (int i = 0; i < pairNum; i++) {
		cin >> num1 >> num2;
		computers[num1].push_back(num2);
		computers[num2].push_back(num1);
	}

	dfs(1);
	cout << answer;
}