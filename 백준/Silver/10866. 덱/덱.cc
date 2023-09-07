#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

class Deque {
private:
	Node* front;
	Node* rear;
	int size;

public:
	Deque();
	void push_front(int n);
	void push_back(int n);
	int pop_front();
	int pop_back();
	int Size();
	bool isEmpty();
	int Front();
	int Back();
};

Deque::Deque()
{
	front = rear = nullptr;
	size = 0;
}

void Deque::push_front(int n)
{
	Node* newNode = new Node();
	newNode->data = n;
	newNode->prev = nullptr;
	newNode->next = nullptr;
	if (isEmpty()) {
		front = rear = newNode;
	}
	else {
		newNode->next = front;
		front->prev = newNode;
		front = front->prev;
	}
	size++;
}

void Deque::push_back(int n)
{
	Node* newNode = new Node();
	newNode->data = n;
	newNode->prev = nullptr;
	newNode->next = nullptr;
	if (isEmpty()) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		newNode->prev = rear;
		rear = rear->next;
	}
	size++;
}

int Deque::pop_front()
{
	if (isEmpty()) return -1;
	Node* delNode = front;
	int val = delNode->data;
	if (front->next == nullptr) {
		front = rear = nullptr;
	}
	else {
		front = front->next;
		front->prev = nullptr;
	}
	size--;
	delete delNode;
	return val;
}

int Deque::pop_back()
{
	if (isEmpty()) return -1;
	Node* delNode = rear;
	int val = delNode->data;
	if (rear->prev == nullptr) {
		front = rear = nullptr;
	}
	else {
		rear = rear->prev;
		rear->next = nullptr;
	}
	size--;
	delete delNode;
	return val;
}

int Deque::Size()
{
	return size;
}

bool Deque::isEmpty()
{
	return size == 0;
}

int Deque::Front()
{
	if (isEmpty()) return -1;
	return front->data;
}

int Deque::Back()
{
	if (isEmpty()) return -1;
	return rear->data;
}

int main()
{
	cin.tie(0);

	Deque dq;
	int N;
	cin >> N;

	string order;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> order;
		if (order == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (order == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (order == "pop_front") cout << dq.pop_front() << '\n';
		else if (order == "pop_back") cout << dq.pop_back() << '\n';
		else if (order == "size") cout << dq.Size() << '\n';
		else if (order == "empty") cout << dq.isEmpty() << '\n';
		else if (order == "front") cout << dq.Front() << '\n';
		else if (order == "back") cout << dq.Back() << '\n';
	}
}