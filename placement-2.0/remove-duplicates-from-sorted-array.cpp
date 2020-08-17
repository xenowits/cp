#include <bits/stdc++.h>
using namespace std;

int solve (vector<int> &A) {
	int n = A.size();
    if (n == 1) {
        return 1;
    }

    int l = 1, r = 1;
    while (l < n && A[l-1] != A[l]) {
        l += 1;
    }
    r = l;
    if (l == n) {
        //NO DUPLICATES AT ALL
        return n;
    }

    // cout << r << " " << n << endl;
    while (r < n) {
        while (r+1 < n && (A[r] == A[r+1])) {
            r += 1;
        }
        r += 1;
        // cout << l << " " << r << " " << A[l] << " " << A[r] << endl;
        A[l] = A[r];
        l += 1;
    }
    return l-1;
}

int main() {
	int n;
	// cin >> n;
	// vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	vector<int> v = {0, 1, 3};
	// for (int i = 0; i < n; i += 1) {
	// 	cin >> v[i];
	// }
	n = v.size();
	cout << solve(v) << endl;
	for (int i = 0; i < n; i += 1) {
		cout << v[i] << " ";
	}
}
