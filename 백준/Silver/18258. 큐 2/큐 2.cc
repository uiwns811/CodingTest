#include <iostream>
using namespace std;

const int MAX = 2'000'001;

struct Node {
	int data;
	Node* next;
};

class Queue {
private:
	Node* front;
	Node* rear;
	int size;

public:
	Queue();

	void Push(int n);
	int Pop();
	int Size();
	bool IsEmpty();
	int Front();
	int Back();
};

Queue::Queue()
{
	front = rear = nullptr;
	size = 0;
}

void Queue::Push(int n)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->next = nullptr;
	if (IsEmpty()) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = rear->next;
	}
	size++;
}

int Queue::Pop()
{
	if (IsEmpty()) return -1;
	Node* deleteNode = front;
	int data = deleteNode->data;
	front = deleteNode->next;
	size--;
	free(deleteNode);
	return  data;
}

int Queue::Size()
{
	return size;
}

bool Queue::IsEmpty()
{
	return size == 0;
}

int Queue::Front()
{
	if (IsEmpty()) return -1;
	return front->data;
}

int Queue::Back()
{
	if (IsEmpty()) return -1;
	return rear->data;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Queue q;

	int N;
	cin >> N;
	string order;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> order;
		if (order == "push") {
			cin >> num;
			q.Push(num);
		}
		else if (order == "pop") cout << q.Pop() << '\n';
		else if (order == "size") cout << q.Size() << '\n';
		else if (order == "empty") cout << q.IsEmpty() << '\n';
		else if (order == "front") cout << q.Front() << '\n';
		else if (order == "back") cout << q.Back() << '\n';
	}

}