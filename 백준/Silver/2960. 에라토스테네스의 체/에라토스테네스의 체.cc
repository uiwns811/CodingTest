#include <iostream>
using namespace std;

bool arr[1001] = { false, };
int n, k;
int value = -1;

int GetValue()
{
	int cnt = 0;
	while (true) {
		for (int i = 2; i <= n; i++) {
			if (!arr[i]) {
				for (int j = i ; j <= n; j += i) {
					if (!arr[j]) {
						arr[j] = true;
						if (++cnt == k) return j;
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	
	cout << GetValue() << endl;
}