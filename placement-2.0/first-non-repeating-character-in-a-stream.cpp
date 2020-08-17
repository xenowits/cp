#include<iostream>
#include <limits.h>
#include <vector>

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
	bool Empty();
	int Front();
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
// 		cout << "Queue is Empty" << endl;
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

bool Queue::Empty() {
    if (front == -1) {
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
		string temp;
        cin >> n;
        string str = "";
		for (int i= 0; i < n; i += 1) {
			cin >> temp;
			str += temp;
		}

        vector<int> freq(26, 0);
        Queue q(n+5);

        for (int i = 0; i < n; i += 1) {
			freq[str[i] - 'a'] += 1;

            if (i == 0) {
                q.Push(str[i] - 'a');
                cout << str[i] << " ";
            } else {
                if (freq[str[i] - 'a'] == 1) {
                    q.Push(str[i] - 'a');
                }

                while (q.Empty() == false && (freq[q.Front()] > 1)) {
                    int temp1 = q.Pop();
                }

                if (q.Empty()) {
                    cout << "-1" << " ";
                } else {
                    cout << (char)('a' + q.Front()) << " ";
                }
            }
        }

        cout << endl;
    }
	return 0;
}
