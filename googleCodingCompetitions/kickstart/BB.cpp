//xenowi`tz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define MAXN 400005
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, cnt = 1;
	cin >> t;

	while (cnt <= t) {
		int n;
		cin >> n;
		vector<int> S(n), E(n), L(n);
		fori(i,0,n-1) {
			cin >> S[i] >> E[i] >> L[i];
		}
		//input done
		//we solve this problem using dynamic programming -- equivalent to knapsack problem
		vector<vector<int> > dp(n+1, vector<int>(105,0));
		int ans = INT_MIN;
		fori(i,0,n) {
			fori(j,0,102) {
				bool can_be_taken = false;
				//check energy wise
				//also check time wise

				if ((E[i] - j*L[i] > 0) || (j < S[i]))
					can_be_taken = true;

				if (i == 0 || j == 0) {
					dp[i][j] = 0;
				} else if (can_be_taken) {
					//we can take this pill or not ---> thus two cases
					dp[i][j] = max(dp[i-1][j], E[i]-j*L[i]+dp[i-1][j-S[i]]);
				} else {
					//we cannot take as it is expired
					//only way is to take maximum of what we have got
					//from the last (i-1) items in time j
					dp[i][j] = dp[i-1][j];
				}
				
				if (i == n)
					ans = max(ans, dp[i][j]), cout << i << " " << j << " " << dp[i][j] << endl;
			}
		}
		//find max among dp[n][i]
		cout << "Case #" << cnt << ": " << ans << endl;
		cnt += 1;
	}	
	
	return 0;
}

