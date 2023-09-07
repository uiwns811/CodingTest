#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
	stack<double> st;
	int N;
	string order;
	double answer;
	cin >> N;
	cin >> order;

	unordered_map<char, int> um;
	int num;
	char alpha = 'A';
	for (int i = 0; i < N; i++) {
		cin >> num;
		um[alpha++] = num;
	}

	for (int i = 0; i < order.length(); i++) {
		if (isalpha(order[i])) {
			st.push((double)um[order[i]]);
		}
		else {
			double rhs = st.top();
			st.pop();
			double lhs = st.top();
			st.pop();
			if (order[i] == '+') st.push(lhs + rhs);
			else if (order[i] == '-') st.push(lhs - rhs);
			else if (order[i] == '*') st.push(lhs * rhs);
			else if (order[i] == '/') st.push(lhs / rhs);
		}
	}
	printf("%.2f\n", st.top());
}