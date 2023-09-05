#include <iostream>
#include <cmath>
using namespace std;

bool check[1000001] { false };

int main()
{
    int M, N;
    cin >> M >> N;

    check[0] = true;
    check[1] = true;

    for (int i = 2; i <= sqrt(N) ; i++) {
        if (check[i]) continue;
        for (int j = i * 2; j <= N; j += i)
            check[j] = true;
    }

    for (int i = M; i <= N; i++) {
        if (!check[i])
            cout << i << "\n";
    }
}