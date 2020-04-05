#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define MAXN 200005
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

vector<int> adj[MAXN];
vector<ll> S(MAXN,0), A(MAXN,0), minvalue(MAXN,-1);
vector<bool> visited1(MAXN,false), visited2(MAXN,false);

void dfs(int s, int total) {
		visited2[s] = true;
		//cout << s << " haha fuck dfs " << total << endl;
		if (adj[s].size() == 1 && S[s] == -1) {
			//s is a leaf at even depth
			A[s] = 0;
			return;
		} 
		if (S[s] == -1)
			A[s] = minvalue[s]-total;
		else
			A[s] = S[s]-total;
		//cout << A[s] << " for index " << s << endl;
	        if (A[s] < 0) {
                        cout << -1 << endl;
                        exit(0);
                }
                total += A[s];
                for (auto x : adj[s]) {
                        if (!visited2[x]) {
			//	cout << x << " inside baby" << endl;
                                dfs(x,total);
                        }
                }
                total -= A[s];
}

void mindfs(int s) {
	visited1[s] = true;
	ll ans = INT_MAX;
	for(auto x : adj[s]) {
		if (!visited1[x]) {
			mindfs(x);
			ans = min(ans,S[x]);
		}
	}
	if (ans == INT_MAX)
		minvalue[s] = -1;
	else
		minvalue[s] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, temp;
	cin >> n;

	fori(i,2,n) {
		cin >> temp;
		adj[temp].pb(i);
		adj[i].pb(temp);
	}
	
	fori(i,1,n) {
		cin >> S[i];
	}
	mindfs(1);
//	fori(i,1,n) {
//		cout << i << " " << minvalue[i] << endl;
	//}
	//return 0;
	//visited.resize(MAXN,false);
	dfs(1,0);
	ll ans = 0;
	fori(i,1,n) {
		ans += A[i];
	}
	cout << ans << endl;
	return 0;
}
