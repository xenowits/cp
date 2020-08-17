class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int m = a.length(), n = b.length();

        int dp[m+1][n+1];

        //first i characters of first string
        //first j characters of second string

        for (int i = 0; i <= m; i += 1) {
            for (int j = 0; j <= n; j += 1) {
                if (i == 0 || j == 0) {
                    //one is an empty string
                    dp[i][j] = 0;
                } else if (a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};
