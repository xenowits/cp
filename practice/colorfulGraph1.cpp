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
  set<int> s;
  vector<int> color(n+1);
  fori(i,1,n)
  {
    cin >> temp;
    s.insert(temp);
    color[i] = temp;
  }
  fori(i,1,m)
  {
    cin >> a >> b;
    if (color[a] != color[b])
    {
      adj[color[a]].insert(color[b]);
      adj[color[b]].insert(color[a]);
      //cout << "a and b " << a << " " << b << " " << color[a] << " " << color[b] << endl;
    }
  }
  ll ans = INT_MIN,ans_color;
  for (int x : s)
  {
    //cout << x << endl;
    // cout << "color is " << x << endl;
    // for(int p : adj[x])
    //   cout << p << " ";
    //cout << endl;
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
    if (adj[x].empty())
      continue;
    temp = adj[x].size();
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
    //cout << temp << " is temp and anscolor is " << ans_color << endl;
  }
  if (ans == INT_MIN)
    cout << *s.begin() << endl;
  else
    cout << ans_color << endl;
  return 0;
}
