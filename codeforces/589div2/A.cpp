#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

bool solve(ll x)
{
  set<int> s;
  int cnt = 0;
  while (x)
  {
    s.insert(x%10);
    x = x/10;
    cnt += 1;
  }
  if (s.size() == cnt)
    return 1;
  else
    return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll l, r;
  cin >> l >> r;

  fori(i,l,r)
  {
    if (solve(i))
    {
      cout << i << endl;
      exit(0);
    }
  }

  cout << -1 << endl;

  return 0;
}
