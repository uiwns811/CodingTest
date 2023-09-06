#include <iostream>
#include <stack>
using namespace std;

int main()
{	
	int T;
	cin >> T;

	string order;
	for (int i = 0; i < T; i++) {
		stack<char> st;
		cin >> order;
		for (int j = 0; j < order.length(); j++) {
			if (st.empty()) { st.push(order[j]); continue; }
			else if (order[j] == '(') { st.push(order[j]); continue; }
			else if (st.top() == ')') { st.push(order[j]); continue; }
			else st.pop();
		}
		if (st.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}