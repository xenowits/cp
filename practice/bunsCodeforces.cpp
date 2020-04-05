//xenowi`tz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define MAXN 400005
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

int dp[15][1005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	int n, m, c0, d0;
	cin >> n >> m>> c0 >> d0;

	vector<int> A(m+1,0), B(m+1,0), C(m+1,0), D(m+1,0);
	fori(i,1,m) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	//among first 0 buns obviously dp will be 0
	for (int i = 0; i <= n; i++) {
		dp[0][i] = 0;
	}
	//dp(i,j) means among first i bun types 1.....i
	//and with total dough grams equal to j
	//what is the maximum amount one can earn?
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			//among first i bun types
			//and remaining amount j
			//what is the maximum price u can obtain
			dp[i][j] = 0;
			for (int k = 0; k <= 1000; k++) {
				//can we buy k of ith type
				if ((k*C[i] <= j) && (k*B[i] <= A[i])) {
					dp[i][j] = max(dp[i][j], k*D[i]+dp[i-1][j-k*C[i]]);					
				}	
			}
		}
	}

	int ans = INT_MIN;

	for(int i = 0; i <= n; i++) {
		//cout << dp[m][i] << " " << ((n-i)/c0)*d0 << endl;
		ans = max(ans, (dp[m][i]+((n-i)/c0)*d0));
	}

	cout << ans << endl;

	return 0;
}
