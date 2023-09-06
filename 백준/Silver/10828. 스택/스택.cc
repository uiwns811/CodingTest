#include <iostream>
using namespace std;

class Stack {
private:
	int arr[10'001];
	int ptr = -1;

public:
	void push(int n)
	{
		arr[++ptr] = n;
	}

	int pop()
	{
		if (ptr < 0) return -1;
		return arr[ptr--];
	}

	int size()
	{
		return ptr + 1;
	}

	int empty()
	{
		if (ptr < 0) return 1;
		else return 0;
	}

	int top()
	{
		if (ptr < 0) return -1;
		return arr[ptr];
	}
};

int main()
{
	Stack myStack;
	int N;
	cin >> N;

	string order;
	int num;
	
	for (int i = 0; i < N; i++) {
		cin >> order;

		if (order == "push") {
			cin >> num;
			myStack.push(num);
		}
		else if (order == "pop") cout << myStack.pop() << endl;
		else if (order == "size") cout << myStack.size() << endl;
		else if (order == "empty") cout << myStack.empty() << endl;
		else if (order == "top") cout << myStack.top() << endl;
	}
}