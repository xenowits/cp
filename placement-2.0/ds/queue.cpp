#include <iostream>
#include <limits.h>
using namespace std;

struct Queue {
	int rear, front, size;
	int *arr;

	Queue (int s) {
		front = rear = -1;
		size = s;
		arr = new int[s];
	}

	void Push(int val);
	int Pop();
	int Front();
	// void printQueue();
};

void Queue::Push(int val) {
	if ((front == 0 && rear == size-1) ||
		(rear == (front-1)%(size-1))) {
			cout << "Queue is full" << endl;
			return;
	} else if (front == -1) {
		//first element
		front = rear = 0;
		arr[rear] = val;
	} else if (rear == size-1 && front != 0) {
		rear = 0;
		arr[rear] = val;
	} else {
		rear += 1;
		arr[rear] = val;
	}
}

int Queue::Pop() {
	if (front == -1) {
		cout << "Queue is Empty" << endl;
		return INT_MIN;
	}
	int data = arr[front];
	arr[front] = -1;

	if (front == rear) {
		front = -1;
		rear = -1;
	} else if (front == size-1) {
		front = 0;
	} else {
		front += 1;
	}

	return data;
}

int Queue::Front() {
	if (front == -1) {
		cout << "Queue is Empty" << endl;
		return INT_MIN;
	}
	return arr[front];
}

int main() {
	int n = 5;
	Queue q(n);
	q.Push(1);
	cout << q.Pop() << endl;
}
