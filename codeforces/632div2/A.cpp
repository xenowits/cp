//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e6+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (n == 2 && m == 2) {
			cout << "BB" << endl << "WB" << endl;
			continue;
		}
		
		char coloring[n+1][m+1];
		for(int i = 1; i <= n; i++) {
			int j, j2;
			if (i%2 == 0) {
				j = 2;
				j2 = 1;	
			} else {
				j = 1;
				j2 = 2;
			}
			
			for (;j <= m; j+=2) {
				coloring[i][j] = 'B';
			}
			for(; j2 <= m; j2 += 2) {
				coloring[i][j2] = 'W';
			}
		}
		if ((n*m)%2 == 0) {
			//make one white black that's it
			coloring[1][2] = 'B';
		}
		fori(i,1,n) {
			fori(j,1,m) {
				cout << coloring[i][j];
			}
			cout << endl;
		}
	}	

	return 0;
}
