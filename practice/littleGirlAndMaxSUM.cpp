#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,q;
  ll l,r;
  cin >> n >> q;

  vector<ll> ans(n+2,0), v(n+1);

  fori(i,1,n)
    cin >> v[i];

  sort(v.begin()+1, v.end(), greater<int>());

  while (q--)
  {
    cin >> l >> r;
    ans[l] += 1;
    ans[r+1] -= 1;
  }

  fori(i,1,n)
    ans[i] = ans[i-1]+ans[i];

  sort(ans.begin()+1,ans.end(), greater<int>());

  unsigned long long ans1 = 0;

  fori(i,1,n)
  {
    //cout << ans[i] << " " << v[i] << endl;
    ans1 += ans[i]*v[i];
  }

  cout << ans1 << endl;

  return 0;
}
