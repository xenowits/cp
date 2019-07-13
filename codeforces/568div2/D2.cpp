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

set<ll> fv[200001];
set<ll> bv[200001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;ll tp;
  cin >> n;
  vector<pair<ll,ll> > v;
  vector<bool> truth(n,true);
  fori(i,0,n-1)
  {
    cin >> tp;
    v.pb(mk(tp,i+1));
  }
  if (n == 2)
  {
    cout << 1 << endl;
    return 0;
  }
  sort(v.begin(),v.end());
  // for(auto a : v)
  //   cout << a.first << " ";
  // cout << endl;
  set<ll> ss;
  fori(i,2,n-1)
  {
    ll t = v[i-1].first-v[i-2].first;
    if (i == 2)
    {
      fv[i].insert(t);
      ss = fv[i];
    }
    else
    {
      ss.insert(t);
      if (ss.size() > 1)
        truth[i] = false;
      else
        fv[i] = ss;
    }
  }
  // fori(i,2,n-1)
  // {
  //   for(auto a : fv[i])
  //     cout << a << " ";
  //   cout << endl;
  // }
  // cout << "all done and dusted" << endl;
  ford(i,n-3,0)
  {
    ll t = v[i+2].first - v[i+1].first;
    if (i == n-3)
    {
      bv[i].insert(t);
      ss = bv[i];
    }
    else
    {
      ss.insert(t);
      if (ss.size() > 1)
        truth[i] = false;
      else
        bv[i] = ss;
    }
  }
  // fori(i,0,n-3)
  // {
  //   for(auto a : bv[i])
  //     cout << a << " ";
  //   cout << endl;
  // }
  // cout << "ans will follow" << endl;
  fori(i,0,n-1)
  {
    // ll temp = 0;
    // if (!bv[i].empty())
    //   temp = *(bv[i].begin());
    // if (i == n-2)
    // {
    //   cout << fv[i].size() << " hilo " << temp << " " << v[n-1].first-v[n-3].first << endl;
    // }
    if (truth[i] && i == 0 && bv[i].size() == 1)
    {
      cout << v[i].second << endl;
      return 0;
    }
    if (truth[i] && i == 1 && bv[i].size() == 1 && (*(bv[i].begin()) == v[2].first-v[0].first))
    {
      cout << v[i].second << endl;
      return 0;
    }
    if (truth[i] && i == n-1 && fv[i].size() == 1)
    {
      cout << v[i].second << endl;
      return 0;
    }
    if (truth[i] && i == n-2 && fv[i].size() == 1 && (*(fv[i].begin()) == v[n-1].first-v[n-3].first))
    {
      cout << v[i].second << endl;
      return 0;
    }
    else if (truth[i] && i>1 && i <n-2 && (fv[i].size() == bv[i].size() == 1) && (*fv[i].begin() == *bv[i].begin()) && (v[i+1].first-v[i-1].first == *bv[i].begin()))
    {
      cout << v[i].second << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
