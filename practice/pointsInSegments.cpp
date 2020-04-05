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
	
	int n,m,x,y;
	cin >> n >> m;
	vector<pi> v;
	fori(i,1,n) {
		cin >> x >> y;
		v.pb(mk(x,y));
	}
	int cnt = 0;
	vector<int> ans;
	fori(i,1,m) {
		bool done = false;
		for (auto x : v) {
			if (i >= x.fs && i <= x.sc) {
				done = true;
				break;
			}
		}
		if (!done) {
			ans.pb(i);
		}
	}
	cout << ans.size() << endl;
	for(int x : ans) {
		cout << x << " ";
	}
	return 0;
}
