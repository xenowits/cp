#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define DEBUG 1
#define cerr if (DEBUG) cerr
#define fprintf if (DEBUG) fprintf
#define local freopen("in.txt", r, stdin);
#define test cerr << "hi\n";
#define tr(x) cerr << #x << ' ' << x << '\n';
#define fi first
#define se second
#define HH1 402653289
#define HH2 1610612741
#define INF 0x3f3f3f3f
#define tii tuple<int, int, int>
#define npos string::npos
#define ll long long

using namespace std;

#define MOD 1000000007LL
#define MAXN 300005

int n, m, k;
int a[3600];

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int front = m-1;
	k = min(k, front);
  cout << k << " is k" << endl;
	int ans = 0;

	for (int tl = 0; tl <= k; tl++) {
		int tr = k - tl;
		int mx = INF;
    cout << tl << " is tl and the next is tr " << tr << endl;
		for (int al = 0; al <= front-k; al++) {
			int ar = front-k-al;
      cout << al << " is al and ar " << ar << endl;
      cout << tl+al+1 << " " << a[tl+al+1] << " " << n-tr-ar << " " << a[n-tr-ar] << endl;
			mx = min(mx, max(a[tl+al+1], a[n-tr-ar]));
		}
		ans = max(ans, mx);
	}

	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);


	int t; cin >> t;
	while (t--) {
		solve();
	}
}
