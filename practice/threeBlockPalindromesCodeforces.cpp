//xenowi`tz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define MAXN 5005
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

	int t;
	cin >> t;
	int no_of_chars = 26;

	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n+1,0);
		fori(i,1,n) {
			cin >> arr[i];
		}

		vector<vector<int> > dp(n+1, vector<int>(no_of_chars+1,0));
		vector<int> first_occurence(no_of_chars+1,0), last_occurence(no_of_chars+1,0);

		fori(i,1,n) {
			fori(j,1,no_of_chars) {
				dp[i][j] = dp[i-1][j];
			}
			dp[i][arr[i]] += 1;
			if (first_occurence[arr[i]] == 0) {
				first_occurence[arr[i]] = i;
			}
		}

		ford(i,n,1) {
			if (last_occurence[arr[i]] == 0) {
				last_occurence[arr[i]] = i;
			}
		}

		int ans = -1;

		fori(i,1,26) {
			ans = max(ans, dp[n][i]);
		}

		fori(i,1,no_of_chars) {

			int l = first_occurence[i], r = last_occurence[i];

			if (l == 0) {
				//char i not found
				continue;
			}

			while (l < r) {

				if (dp[l][i] == (dp[n][i] - dp[r-1][i])) {
					if ( r-l >= 2) {
						//there can be y elements
						//find which char is most frequent
						int maxu = -1;
						fori(ai, 1, no_of_chars) {
							maxu = max(maxu, dp[r-1][ai] - dp[l][ai]);
						}
						ans = max(ans, maxu+2*dp[l][i]);
					} else {
						//no element in between
						ans = max(ans, 2*dp[l][i]);
					}
					//move them fast
					l += 1;
					while (l <= n) {
						if (arr[l] == i) {
							break;
						}
						l += 1;
					}
				} else {
					//either move l to right or r to left
					while (l < r) {
						if (dp[l][i] > (dp[n][i] - dp[r-1][i])) {
							r -= 1;
						} else if (dp[l][i] < (dp[n][i] - dp[r-1][i])) {
							l += 1;
						} else {
							break;
						}
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
