#include <bits/stdc++.h>
using namespace std;

long int solve(vector<int> arr, int n) {
	if (n == 1) {
		return arr[0];
	}

	if (n == 2) {
		return max(arr[0], arr[1]);
	}

	vector<int> dp(n+1,0);
	int max_so_far = arr[0];
	int max_ans = -1e6;

	for (int i = 0; i < n; i += 1) {
		if (i < 2) {
			dp[i] = arr[i];
		} else {
			int temp = arr[i] + max_so_far;
			if (max_so_far >= 0) {
				dp[i] = temp;
			} else {
				dp[i] = arr[i];
			}
			//now update max_so_far
			max_so_far = max(max_so_far, dp[i-1]);
		}
		max_ans = max(max_ans, dp[i]);
		// cout << i << " " << dp[i] << " " << max_so_far << endl;
	}

	return max_ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i += 1) {
		cin >> arr[i];
	}

	cout << solve(arr, n);
}
