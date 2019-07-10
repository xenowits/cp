#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>

set<ll> adj[100005];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m,temp,a,b;
  cin >> n >> m;
  vector<int> color(n+1);
  set<int> s;
  fori(i,1,n)
  {
    cin >> temp;
    color[i] = temp;
    s.insert(temp);
  }
  fori(i,1,m)
  {
    cin >> a >> b;
    if (color[a] != color[b])
    {
      adj[color[a]].pb(color[b]);
      adj[color[b]].pb(color[a]);
    }
  }
  //cout << s.size() << " is set size " << *(s.begin()) << endl;
  ll ans = INT_MIN, ans_k;
  for(auto x : s)
  {
    if (adj[x].empty())
      continue;
    temp = adj[x].size();
    if (temp > ans)
    {
      ans = temp;
      ans_k = x;
    }
    else if (temp == ans && x < ans_k)
    {
      ans_k = x;
    }
  }
  //cout << "kya hua" << endl;
  if (ans == INT_MIN)
    cout << *s.begin() << endl;
  else
    cout << ans_k << endl;
  //cout << "kaha h" << endl;
  return 0;
}
