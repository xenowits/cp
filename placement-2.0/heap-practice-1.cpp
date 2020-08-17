#include<iostream>
using namespace std;

struct MaxHeap {
    int size;
    int *arr;
    MaxHeap(int sz, int a[]) {
        size = sz;
        // int n = sizeof(arr)/sizeof(arr[0]);
        arr = new int[sz];
        for (int i = 0; i < sz; i += 1) {
            arr[i] = a[i];
        }
    }
};

void maxHeapify(MaxHeap *heap, int indx) {
    int l = 2*indx+1;
    int r = l+1;

    int n = heap->size, largest = indx;

    if (l < n && heap->arr[l] > heap->arr[indx]) {
        largest = l;
    }

    if (r < n && heap->arr[r] > heap->arr[largest]) {
        largest = r;
    }

    if (largest != indx) {
        swap(heap->arr[indx], heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(MaxHeap *heap) {
    int n = heap->size;

    for (int i = n/2-1; i >= 0; i -= 1) {
        maxHeapify(heap, i);
    }
}

int extractMax(MaxHeap *heap) {
    int max_ans = heap->arr[0];
    int n = heap->size;
    heap->arr[0] = heap->arr[n-1];
    maxHeapify(heap, 0);
    heap->size -= 1;
    return max_ans;
}

void printHeap(MaxHeap *heap) {
    int n = heap->size;
    for (int i = 0; i < n; i += 1) {
        cout << heap->arr[i] << " ";
    }
    cout << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    for (int i = 0; i < n; i += 1) {
	        cin >> arr[i];
	    }
	    MaxHeap *heap = new MaxHeap(n, arr);
	    buildMaxHeap(heap);
	    for (int i = 0; i < k; i += 1) {
	        // printHeap(heap);
	        cout << extractMax(heap) << " ";
	    }
	    cout << endl;
	}

	return 0;
}
