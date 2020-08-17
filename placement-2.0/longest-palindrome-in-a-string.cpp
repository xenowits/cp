#include<bits/stdc++.h>
using namespace std;

#define fori(i, a, b) for (int i = a; i < b; i += 1)

string solve(string s) {
    int n = s.length();
    vector<vector<bool> > dp (n, vector<bool> (n, false));
    fori(i, 0, n) {
        dp[i][i] = true;    //single characters are palindromes
    }

    int max_len = 1;

    fori(j, 1, n) {
        fori(i, 0, j) {
            //s[i..i+1...j-1..j]
            if (i+1 == j) {
                if (s[i] == s[j]) {
                    dp[i][j] = true;
                    max_len = max(max_len, 2);
                }
            } else if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                max_len = max(max_len, j-i+1);
            }
        }
    }

    if (max_len == 1) {
        return s.substr(0,1);
    }

    fori(j, 1, n) {
        fori(i, 0, j) {
            if (dp[i][j] && (j-i+1 == max_len)) {
                //first substring ka khitaab tumko hi jata h
                return s.substr(i, max_len);
            }
        }
    }

    return "hello";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    string str;
	    cin >> str;
	    cout << solve(str) << endl;
	}
	return 0;
}
