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
  ll n;
  cin >> n;
  vector<ll> v(n+1);vector<pi> change_vector, zero_vector;
  ll pos = 0, neg = 0, zer = 0;
  fori(i,1,n)
  {
    cin >> v[i];
    if (v[i] == 0)
    {
      pos += 1;
      zero_vector.pb(mk(v[i],i));
      zer += 1;
    }
    else if (v[i] < 0)
      neg += 1;
    else
    {
      change_vector.pb(mk(v[i],i));
      pos += 1;
    }
  }
  if (zer == n)
  {
    fori(i,1,n)
    {
      
    }
  }
  if (!change_vector.empty())
    sort(change_vector.begin(), change_vector.end(), greater<pi>());
  vector<ll> ans_v = v;
  //basically we r changing the positive array
  for (auto x : zero_vector)
  {
    ans_v[x.second] = -1;
    pos -= 1;
    neg += 1;
  }
  if (neg%2 == 0)
  {
    if (pos%2 == 0)
    {
      for (auto x : change_vector)
        ans_v[x.second] = -x.first-1;
    }
    ll cnt = 0;
    if (pos%2 == 1)
    {
      for (auto x : change_vector)
      {
        if (cnt == pos-1)
          break;
        ans_v[x.second] = -x.first-1;
        cnt += 1;
      }
    }
  }
  if (neg%2 == 1)
  {
    if (pos%2 == 1)
    {
      for (auto x : change_vector)
        ans_v[x.second] = -x.first-1;
    }
    ll cnt = 0;
    if (pos%2 == 0)
    {
      for (auto x : change_vector)
      {
        if (cnt == pos-1)
          break;
        ans_v[x.second] = -x.first-1;
        cnt += 1;
      }
    }
  }
  fori(i,1,n)
    cout << ans_v[i] << " ";
  cout << endl;
  return 0;
}
