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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, hell = 1;
	cin >> t;

	while (hell <= t) {
		int n, k, p;
		cin >> n >> k >> p;
		int arr[n+1][k+1];
		fori(i,0,n-1) {
			fori(j,0,k-1) {
				cin >> arr[i][j];
			}
		}
		//okay so n pointer technique
		vector<int> pointers(n,0);
		int cnt = 0;
		ll ans = 0;
		while (cnt < p) {
			//find max among the arrays
			ll temp_max = INT_MIN, temp_indx = -1;
			fori(i,0,n-1) {
				if (pointers[i] < k && arr[i][pointers[i]] > temp_max) {
					temp_max = arr[i][pointers[i]];
					temp_indx = i;
				}	
			}
			ans += temp_max;
			pointers[temp_indx] += 1;
			//cout << temp_max << " hell " << temp_indx << " " << cnt << endl;
			cnt += 1;
		}
		cout << "Case #" << hell << ": " << ans << endl;
		hell += 1;
	}	
	
	return 0;
}

