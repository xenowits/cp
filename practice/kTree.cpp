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

vector<ll> c[1<<5+1];
vector<ll> adj[1<<5+1];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m,temp,a,b;
  cin >> n >> m;
  set<int> s;
  vector<int> color(n+1);
  fori(i,1,n)
  {
    cin >> temp;
    // c[temp].pb(i);
    s.insert(temp);
    color[i] = temp;
  }
  unordered_map<ll,ll> umap;
  fori(i,1,m)
  {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
    if (color[a] != color[b])
    {
      umap[a] += 1;
      umap[b] += 1;
      cout << "a and b " << a << " " << b << " " << color[a] << " " << color[b] << endl;
    }
  }
  ll ans = INT_MIN,ans_color;
  for (int x : s)
  {
    //cout << x << endl;
    cout << "color is " << x << endl;
    //temp = 0;
    // for (int p : c[x])
    // {
    //   for (int q : adj[p])
    //   {
    //     if (color[q] != x)
    //     {
    //       //cout << p << " " << q << " " << x << endl;
    //       temp += 1;
    //     }
    //   }
    // }
    //cout << "temp is " << temp << endl;
    temp = umap[x];
    //cout << temp << " is temp" << endl;
    if (temp > ans)
    {
      ans = temp;
      ans_color = x;
    }
    else if (temp == ans && x < ans_color)
    {
      ans_color = x;
    }
    cout << temp << " is temp and anscolor is " << ans_color << endl;
  }
  cout << ans_color << endl;
  return 0;
}
