#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int n, int m) {
	long long int m_arr[n+1];

	for (int i = 1; i <= n; i += 1) {
		if (i <= m) {
			m_arr[i] = arr[i];
		} else {
			m_arr[i] = arr[i] + m_arr[i-m];
		}
	}

	long long int prev;

	for (int i = 1; i <= n; i += 1) {
		if (i == 1) {
			prev = arr[i];
		} else {
			prev = prev + m_arr[i];
		}
		cout << prev << " ";
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> arr(n+1);
	for (int i = 1 ; i <= n; i += 1) {
		cin >> arr[i];
	}

	sort(arr.begin() + 1, arr.end());

	solve(arr, n, m);
}
