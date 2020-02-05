#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, q;
  cin >> n >> q;
  set<ll> s;
  s.insert(n);

  visited[3][n+1]
  vector<vector<bool> > visited(3, vector<bool>(n+1,false));
  fori(i,1,q) {
    ll r, c;
    cin >> r >> c;
    if (r == 1) {
      if (visited[r+1][c] || visited[r+1][c-1] || visited[r][c+1]) {

      }
    }
  }

  return 0;
}
