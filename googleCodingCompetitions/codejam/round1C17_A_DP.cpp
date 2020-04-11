//xenowi`tz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
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

//dp[n][k]
//dp[i][j] ===> I take plate i as bottom, now what is
//the maximum exposed surface area I can get from last i-1 elements
//basically : for k = 0 to i-1: max(dp[k][j-1]+contribution(kth ele+ith ele))

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, t_count = 1;
	cin >> t;
	long double PI = 3.14159265;

	while (t_count <= t) {
		ll n, k, r, h;
		cin >> n >> k;
		vector<pi> arr;
		arr.pb(mk((ll)0, (ll)0));
		fori(i,1,n) {
			cin >> r >> h;
			arr.pb(mk(r,h));
		}
		sort(arr.begin(), arr.end());
		vector<ll> dp(n+2,0), diff_arr(n+5,0);
		
		fori(i,0,n) {
			diff_arr[i] = (arr[i].fs)*(2*arr[i].sc-arr[i].fs);
		}

		
		ll real_max = numeric_limits<ll>::min();
		fori(i,0,n) {
			real_max = max(real_max, dp[i]);
		}
		long double ans = real_max*PI;
		cout << "Case #" << t_count << ": ";
		cout << fixed << setprecision(7) << ans << endl;	
		t_count += 1;
	}	
	return 0;
}
