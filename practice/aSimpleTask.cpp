#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll dp[(ll)1e6+7][25];

ll first_bit(ll mask)
{
  ll cnt = 0;
  while ((mask&1) == 0)
  {
    mask = (mask >> 1);
    cnt += 1;
  }
  return cnt;
}

ll count_bit(ll mask)
{
  ll cnt = 0;
  while (mask)
  {
    mask = (mask&(mask-1));
    cnt += 1;
  }
  return cnt;
}

bool bit_set(ll mask, ll v)
{
  return (mask&(1 << v));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m,x,y;
  cin >> n >> m;

  vector<int> adj[n];

  fori(i,1,m)
  {
    cin >> x >> y;
    adj[x-1].pb(y-1);
    adj[y-1].pb(x-1);
  }

  // start of solution
  ll maxn = (1 << n)-1;

  ll bit_count = 0, bit_first = 0;
  bool set_bit;

  fori(mask,1,maxn)
  {
    bit_first = first_bit(mask);
    bit_count = count_bit(mask);

    fori(v,0,n-1)
    {
      //cout << mask << " " << v << endl;

      set_bit = bit_set(mask,v);

      if (bit_count == 1 && set_bit)
        dp[mask][v] = 1;
      else if (bit_count > 1 && set_bit && v != bit_first)
      {
        for (auto j : adj[v])
        {
          dp[mask][v] += dp[mask^(1 << v)][j];
        }
      }
      else
        dp[mask][v] = 0;

    }
  }

  ll ans = 0;

  fori(mask,1,maxn)
  {
    bit_first = first_bit(mask);
    bit_count = count_bit(mask);
    if (bit_count >= 3)
    {
      for (auto j : adj[bit_first])
      {
        ans += dp[mask][j];
      }
    }
  }

  cout << ans/2 << endl;

  return 0;
}
