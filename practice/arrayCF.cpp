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
#define sc second
#define fs first

map<int,int> mp;

int main()
{
  ll n,k;
  cin >> n >> k;
  vector<int> v(n+1);
  fori(i,1,n)
    cin >> v[i];

  ll ans_left = -1, ans_right = -1, l = 1, r = 1;

  while (r <= n)
  {
    mp[v[r]] += 1;
    if (mp.size() == k)
      break;
    r += 1;
  }

  ans_right = r, ans_left = l;

  if (mp.size() < k || n < k)
  {
      cout << -1 << " " << -1 << endl;
      return 0;
  }

  while (l <= r)
  {
      l += 1;
      if (mp[v[l-1]] == 1)
        mp.erase(v[l-1]);
      else
        mp[v[l-1]] -= 1;
      if (mp.size() == k)
        ans_left = l;
  }
  cout << ans_left << " " << ans_right << endl;

  return 0;
}
