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
#define pi pair<int,int>

ll solve(vector<ll> v, vector<ll> divisors, int m)
{
  sort(divisors.begin(), divisors.end());
  // for (int a : divisors)
  //   cout << a << " ";
  // cout << endl;
  ll sz = divisors.size();
  unordered_map<ll,ll> umap;
  ll temp;
  fori(i,0,sz-1)
  {
    temp = divisors[i];
    for(ll x : v)
    {
      if (x > temp)
        break;
      if (temp != x && temp%x == 0)
      {
        ll temp2 = temp/x;
        umap[temp] = max(umap[temp],1+temp2*umap[x]);
        //cout << "ghusa maal " << temp << " " << x << " " << temp2 << " " << umap[temp2] << endl;
      }
    }
  }
  // fori(i,1,30)
  //   cout << i << " " << umap[i] << endl;
  return umap[divisors[sz-1]];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q>0)
  {
    ll n,m,s;
    cin >> n >> m;
    vector<ll> v(m);
    fori(i,0,m-1)
      cin >> v[i];
    vector<ll> divisors;
    fori(i,1,sqrt(n))
    {
      if (n%i == 0)
      {
        if (n/i == i)
          divisors.pb(i);
        else
        {
          divisors.pb(i);
          divisors.pb(n/i);
        }
      }
    }
    ll temp = solve(v,divisors,m);
    cout << temp << endl;
    q-=1;
  }
  return 0;
}
