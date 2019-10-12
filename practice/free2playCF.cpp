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

vector<ll> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;

  while (q--)
  {
    ll h, n, temp;
    cin >> h >> n;

    set<ll> st;

    fori(i,1,n)
    {
      cin >> temp;
      st.insert(temp);
      v.pb(temp);
    }
    ll ans = 0, i = 0;
    while (h > 2)
    {
      if (st.find(h-1) == st.end())
        h -= 1;
      else if (st.find(h-2) == st.end())
        h -= 2, ans += 1;
      else
        h -= 2;

      //so far so good

      if (i < n-1 && (h - v[i+1] >= 2))
        h = v[i+1]+1;
      else if (i == n-1)
        h = 0;
      //cout << h << " fdfd " << ans << endl;
      i += 1;
    }
    cout << ans << endl;
    v.clear();
  }

  return 0;
}
