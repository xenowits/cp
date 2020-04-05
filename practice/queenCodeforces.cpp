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
#define MAXN 200005
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<int> adj[MAXN];
vector<bool> visited(MAXN,false);
vector<int> C(MAXN,-1);
vector<int> ans;
int root;

void dfs(int src) {
//	cout << src << " pp " << endl;
	visited[src] = true;
	if (adj[src].size() == 1 && (src != root)) {
		//src is a leaf
		if (C[src] == 1) {
			ans.pb(src);
		}
		return;
	}
	bool flag = true;
	
	for (auto x : adj[src]) {
		if (!visited[x]) {
			if (C[x] == 1 && C[src] == 1) {
			} else {
				flag = false;
			}
			dfs(x);
			//upto now dp of x must have been completed
		}
	}
	if (flag && (src != root))
		ans.pb(src);
}

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

	int x,y,n;
	cin >> n;
	fori(i,1,n) {
		cin >> x >> C[i];
		if (x == -1) {
			root = i;
			continue;
		}
		adj[x].pb(i);
		adj[i].pb(x);
	}
//	fori(i,1,n)
//		cout << i << " " << C[i] << endl;
//	cout << root << endl;
	dfs(root);
	if (ans.size() == 0) {
		cout << -1 << endl;
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
