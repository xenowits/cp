#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n, int k) {
    vector<int> dp(n+2,0);
    for (int i = n-1; i >= 0; i -= 1) {
        if (i == n-1) {
            dp[i] = arr[n-1];
        } else {
            dp[i] = max(dp[i+1]+arr[i], arr[i]);
        }
        // cout << i << " " << dp[i] << endl;
    }
    vector<int> prefix(n+1, 0);
    for (int i = 0; i < n; i += 1) {
        if (i == 0) {
            prefix[i] = arr[i];
        } else {
            prefix[i] = prefix[i-1] + arr[i];
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i+k-1 < n; i += 1) {
        //i......i+k-1
        if (i == 0) {
            ans = max(ans, max(prefix[k-1]+dp[k], prefix[k-1]));
            // cout << max(prefix[k-1]+dp[k], prefix[k-1]) << " " << i << endl;
        } else if (i+k-1 == n-1) {
            ans = max(ans, prefix[i+k-1] - prefix[i-1]);
            // cout << prefix[i+k-1] - prefix[i-1] << " " << i << endl;
        } else {
            ans = max(ans, max(prefix[i+k-1] - prefix[i-1] + dp[i+k],
            prefix[i+k-1] - prefix[i-1]));
            // cout << prefix[i+k-1] - prefix[i-1] + dp[i+k] << " " << i << endl;
        }
    }
    return ans;
}

int solve(vector<int> arr, int n, int k) {
    vector<int> dp(n+2,0);
    for (int i = n-1; i >= 0; i -= 1) {
        if (i == n-1) {
            dp[i] = max(0, arr[n-1]);
        } else {
            dp[i] = max(0, max(dp[i+1]+arr[i], arr[i]));
        }
    }
    vector<int> prefix(n+1, 0);
    for (int i = 0; i < n; i += 1) {
        if (i == 0) {
            prefix[i] = arr[i];
        } else {
            prefix[i] = prefix[i-1] + arr[i];
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i+k-1 < n; i += 1) {
        //i......i+k-1
        if (i == 0) {
            ans = max(ans, prefix[k-1]+dp[k]);
        } else if (i+k-1 == n-1) {
            ans = max(ans, prefix[i+k-1] - prefix[i-1]);
        } else {
            ans = max(ans, (prefix[i+k-1] - prefix[i-1] + dp[i+k]));
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i += 1) {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        cout << solve(arr, n, k) << endl;
    }
	return 0;
}
