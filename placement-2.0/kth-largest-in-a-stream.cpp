#include <bits/stdc++.h>
using namespace std;

struct minHeap {
	int *arr;
	int heap_size;

	minHeap(int a[], int sz) {
		heap_size = sz;
		arr = a;
	}

	void buildMinHeap();
	void minHeapify(int i);
	int getMin();
};

void minHeap::buildMinHeap() {
	//nodes from heap_size/2 to heap_size-1 are leaves
	//so they are min heaps in their own respect
	for (int i = heap_size/2 - 1; i >= 0; i -= 1) {
		minHeapify(i);
	}
}

void Swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void minHeap::minHeapify(int i) {
	int left = 2*i+1, right = 2*i+2;
	int smallest = i;

	if (left < heap_size && (arr[left] < arr[i])) {
		smallest = left;
	}

	if (right < heap_size && (arr[right] < arr[smallest])) {
		smallest = right;
	}

	if (smallest != i) {
		//first swap them - the parent and the child
		Swap(arr[i], arr[smallest]);
		minHeapify(smallest);
	}
}

int minHeap::getMin() {
	if (heap_size == 0) {
		return INT_MAX;
	} else {
		return arr[0];
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;
		int arr[n], first_k[k];
		for (int i = 0; i < n; i += 1) {
			cin >> arr[i];
			if (i < k) {
				first_k[i] = arr[i];
			}
		}

		minHeap mh(first_k, k);
		mh.buildMinHeap();

		for (int i = 0; i < n; i += 1) {
			int to_print = -1;;
			if (i < k-1) {
				cout << "-1 ";
			} else if (i == k-1) {
				//print the minimum first
				cout << mh.getMin() << " ";
			} else if (i >= k) {
				if (mh.getMin() < arr[i]) {
					mh.arr[0] = arr[i];
					mh.minHeapify(0);
				}
				cout << mh.getMin() << " ";
			}
		}

		cout << endl;
	}

	return 0;
}
