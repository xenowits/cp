#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long n, x;
		cin >> n >> x;
		vector<long long> v(n);
		for (int i = 0 ; i < n; i += 1) {
			cin >> v[i];
		}
		sort(v.begin(), v.end(), greater<int>());
		int ans = 0;
		int i = 0, j = 0;
		while (i < n) {
			j = i;
			while (j < n && v[j]*(j-i+1) < x) {
				j += 1;
			}
			if (j < n && v[j]*(j-i+1) >= x) {
				ans += 1;
			}
			// cout << i << " " << j << endl;
			i = j+1;
		}
		cout << ans << endl;
	}
}
