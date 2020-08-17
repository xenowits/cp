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

ll dp[MAXN][4][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll r, c = 3;
	cin >> r;
	
	ll p = 3;		//p denotes no of available colors

	fori(i,1,r) {
		fori(j,1,c) {
			fori(k,1,p) {
				if (i == 1 && j == 1) {
					dp[i][j][k] = 1;
					continue;
				} else if (j == 1) {
					//update dp[i][j][k];
					fori(c_top,1,p) {
						if (c_top != k) {
							dp[i][j][k] += dp[i-1][j][c_top];
						}
					}
					continue;
				} else if (i == 1) {
					//update dp[i][j][k];
                                        fori(c_left,1,p) {
                                                if (c_left != k) {
                                                        dp[i][j][k] += dp[i][j-1][c_left];
                                                }
                                        }
                                        continue;
				}
				//loop through all possible colors of left and top
				//look out for color different from k
				fori(c_left,1,p) {
					fori(c_top,1,p) {
						if (c_left != k && c_top != k) {
							ll ways_to_color_ith_row = dp[i][j-1][c_left] - dp[i-1][j-1][c_left];
							dp[i][j][k] = (ways_to_color_ith_row*dp[i-1][j][c_top])%mod;
						}
					}
				}	
			}					
		}
	}

	ll ans = 0;
	fori(i,1,p) {
		ans += dp[r][c][i];
	}

	fori(i,1,r) {
		fori(j,1,c) {
			fori(k,1,p) {
				cout << i << " " << j << " " << k << " ==> dp value " << dp[i][j][k] << endl;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
