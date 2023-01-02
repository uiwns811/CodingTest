#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solution(int n)
{
    vector<int> vec;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        vec.emplace_back(num);
    }
    
    sort(vec.begin(), vec.end());

    cout << vec.front() << " " << vec.back() << endl;
}

int main()
{
    int N;
    cin >> N;

    Solution(N);
}