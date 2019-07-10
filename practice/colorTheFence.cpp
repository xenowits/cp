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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll v,temp;
  cin >> v;
  vector<pi> a(10);
  fori(i,1,9)
  {
    cin >> temp;
    a[i] = mk(temp,i);
  }
  sort(a.begin()+1,a.end(), [](const pi& a, const pi& b) -> bool
  {
    if (a.first == b.first)
      return a.second > b.second;
    else
      return a.first > b.first;
  });

  for(auto x : a)
    cout << x.first << " " << x.second << endl;
  ll ans = INT_MIN,ansNO;
  vector<ll> vans;
  fori(i,1,9)
  {
    vector<pi> vtemp;
    temp = v/a[i].first;
    ll rem = a[i].first - temp;
    vtemp.pb(mk(a[i].second,temp));
    int j = i+1;
    while (j<10 && rem > 0)
    {
      if (a[j].first < rem)
      {
        rem = rem - 
      }
    }
  }
  return 0;
}
