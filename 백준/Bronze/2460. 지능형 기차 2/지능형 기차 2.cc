#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int in, out;
    int cnt{ 0 };
    int max{ 0 };

    for (int i = 0; i < 10; ++i) {
        cin >> in >> out;
        cnt -= in;
        cnt += out;
        if (cnt > 10000) cnt = 10000;
        if (cnt >= max) max = cnt;
    }

    cout << max;
}