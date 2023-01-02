#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solution(int n)
{
    int pos = 0;
    while (n > 0) {
        int num = n % 2;
        
        if (num == 1) {
            cout << pos << " ";
        }

        n /= 2;
        pos++;
    }
}

int main()
{
    int T, n;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> n;
        Solution(n);
    }
}