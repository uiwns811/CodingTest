#include <iostream>
#include <memory>
using namespace std;

int N;
int arr[15];
int result = 0;

bool SetQueen(int idx)
{
	for (int i = 0; i < idx; i++) {
		if (arr[i] == arr[idx] || abs(idx - i) == abs(arr[idx] - arr[i])) 
			return false;
	}
	return true;
}

void ShowNQueen()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i] == j) cout << 'X';
			else cout << 'O';
		}
		cout << endl;
	}
	cout << endl;
}

void NQueen(int level) 
{
	// level == 열
	if (level == N) {
		result++;
		//ShowNQueen();
	}
	else {
		// level단의 행에서 가능한 애들 세기
		for (int i = 0; i < N; i++) {
			arr[level] = i;
			if (SetQueen(level))
				NQueen(level + 1);
		}
	}
}

int main()
{
	cin >> N;
	
	NQueen(0);

	cout << result;
}