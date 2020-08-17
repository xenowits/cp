#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void MERGE(vector<int> &arr, int p, int q, int r) {
    int l1 = q-p+1;
    int l2 = r-q;
    int left[l1+1], right[l2+1];

    for (int i = 0; i < l1; i += 1) {
        left[i] = arr[i+p];
    }
    left[l1] = INT_MAX;

    for (int i = 0; i < l2; i += 1) {
        right[i] = arr[q+i+1];
    }
    right[l2] = INT_MAX;

    int i = 0, j = 0;

    for (int k = p; k <= r; k += 1) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i += 1;
        } else {
            arr[k] = right[j];
            j += 1;
        }
    }
}

void MERGE_SORT(vector<int> &arr, int p, int r) {
    if (p < r) {
        int q = (p+r)/2;

        MERGE_SORT(arr, p, q);
        MERGE_SORT(arr, q+1, r);

        MERGE(arr, p, q, r);
    }
}

int main() {
	int t;
	cin >> t;

	while (t--) {
	    int n, k;
	    cin >> n >> k;
	    vector<int> arr(n);
	    for (int i = 0; i < n; i += 1) {
	        cin >> arr[i];
	    }
	    MERGE_SORT(arr, 0, n-1);

		// for (auto x : arr) {
		// 	cout << x << " ";
		// }
		// cout << endl;

	    int sum = k, i = 0;
	    for (; i < n; i += 1) {
	        if (sum <= 0 || (arr[i] > sum)) {
	            break;
	        }
	        sum -= arr[i];
	    }
	    cout << i << endl;
	}
	return 0;
}
