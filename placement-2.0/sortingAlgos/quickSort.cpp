#include <iostream>
#include <vector>
using namespace std;

int PARTITION(vector<int> &v, int p, int r) {
	int x = v[r];
	int i = p-1;

	for (int j = p; j <= r-1; j += 1) {
		if (v[j] <= x) {
			i += 1;
			swap(v[i], v[j]);
		}
	}

	swap(v[i+1], v[r]);
	return i+1;
}

void QUICKSORT(vector<int> &v, int p, int r) {
	if (p < r) {
		int q = PARTITION(v, p, r);
		QUICKSORT(v, p, q-1);
		QUICKSORT(v, q+1, r);
	}
}

int main() {
	vector<int> v {1, 5, 2, 7, 4 ,8};
	int n = v.size();

	QUICKSORT(v, 0, n-1);
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}
