#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int in, out;
    vector<int> vec_in, vec_out, vec_num;
    
    for (int i = 0; i < 10; ++i) {
        cin >> in >> out;
        vec_in.emplace_back(in);
        vec_out.emplace_back(out);
    }

    int cnt = 0;
    for (int i = 0; i < 10; ++i) {
        cnt -= vec_in[i];
        vec_num.emplace_back(cnt);
        cnt += vec_out[i];
        vec_num.emplace_back(cnt);
    }

    sort(vec_num.begin(), vec_num.end());
    cout << vec_num.back() << endl;
}