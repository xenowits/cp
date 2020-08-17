#include<iostream>
#include <vector>
#include <limits.h>

using namespace std;

//MATRIX CHAIN MULTIPLICATION

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

        //input done
        n = n-1;
        int dp[n+1][n+1];
        for (int i = 1; i <= n; i += 1) {
            dp[i][i] = 0;
        }

        for (int l = 2; l <= n; l += 1) {
            for (int i = 1; i <= n-l+1; i += 1) {
                int j = i+l-1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k += 1) {
                    dp[i][j] = min(dp[i][j],
                    dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
                }
            }
        }

        cout << dp[1][n] << endl;
    }
	return 0;
}
