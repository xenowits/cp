#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k,temp;
  cin >> n >> k;
  vector<pair<ll,ll> > d,graph;
  fori(i,1,n)
  {
    cin >> temp;
    d.pb(mk(temp,i));
  }
  sort(d.begin(),d.end());
  if (d[0].first != 0)
  {
    cout << -1;
    return 0;
  }
  ll current = d[0].second;
  ll curr_dist = d[0].first;
  ll cnt = 0;
  fori(i,1,n)
  {
    if (d[i].first == 1+curr_dist && cnt <= k)
    {
      graph.pb(mk(current,d[i].second));
      cnt += 1;
    }
    else
    {
      current
    }
  }
  return 0;
}
