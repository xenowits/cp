#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node *next;

	//constructor
	Node(int data) {
		this->data = data;
		next = NULL;
	}	
};

void printTraversal(Node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

void heaps() {
	priority_queue<int> mh;
	mh.push(1);
	mh.push(2);
	mh.push(3);
	while (!mh.empty()) {
		cout << mh.top() << " ";
		mh.pop();
	}

	//minheap
	priority_queue<int, vector<int>, greater<int> > as;
	as.push(5);
	as.push(6);
}

int binary_search(int target) {
	vector<int> v {1,1,2,2,2,3,3,3,3,3,3,4,4,5,5,5,6,6,7,7,8,8,8,8,8};
//	int target = 3;

	int l = 0, r = v.size()-1;
	int mid;
	
	int first_pos = -1;

	while (l <= r) {
		mid = l + (r-l)/2;

		if (v[mid] >= target) {
			first_pos = mid;
			r = mid-1;
		} else if (v[mid] < target) {
			l = mid+1;
		}

//		cout << l << " " << r << endl;
	}

	return first_pos;
}

int main() {
	//construct linked list
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);	
	head->next->next->next = new Node(4);

	printTraversal(head);	
	cout << endl;
	heaps();
	cout << endl;

	cout << binary_search(3) << " ho " << binary_search(4) << endl;
}
