#include <bits/stdc++.h>
using namespace std;

char reachability(int i, int j, string I, string O) {
	if (i < j) {
		for (int p = i; p < j; p += 1) {
			//is it possible to go from p to (p+1)
			if (O[p] == 'Y' && I[p+1] == 'Y') {
				//POSSIBLE : YAY!!
			} else {
				return 'N';
			}
		}
	} else if (i > j) {
		for (int p = i; p > j; p -= 1) {
			//is it possible to go from p to (p-1)
			if (O[p] == 'Y' && I[p-1] == 'Y') {
				//POSSIBLE : YAY!!
			} else {
				return 'N';
			}
		}
	}
	return 'Y';
}

void solve(string I, string O, int n, int t) {
	cout << "Case #" << t << ":" << endl;
	// myfile << "Case #" << t << ":" << endl;
	char ans[n][n];

	//i : starting junction
	//j : destination junction

	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < n; j += 1) {
			if (i == j) {
				ans[i][i] = 'Y';
			} else {
				ans[i][j] = reachability(i, j, I, O);
			}
			cout << ans[i][j];
			// myfile << ans[i][j];
		}
		cout << endl;
		// myfile << endl;
	}
}

int main() {
	// ofstream myfile;
	// myfile.open("travel-restrictions-graded.txt");
	int t;
	cin >> t;
	int cntt = 1;
	while (cntt <= t) {
		int n;
		cin >> n;
		string I, O;
		cin >> I >> O;
		solve(I, O, n, cntt);
		cntt += 1;
	}
	// myfile.close();
}
