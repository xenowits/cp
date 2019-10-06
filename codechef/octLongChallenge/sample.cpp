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
#define MAXN (ll)1e12

ll ansCalculator(int base, string s)
{
  ll ans = 0, temp = 1, n = s.length();
  reverse(s.begin(), s.end());
  fori(i,0,n-1)
  {
    if (s[i] >= '0' && s[i] <= '9')
      ans += temp*(s[i]-'0');
    else
      ans += temp*(s[i]-'A'+10);
    temp *= base;
  }
  if (ans > MAXN)
    return -1;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, b;
  cin >> t;
  string str;

  while (t--)
  {
    int n;
    cin >> n;
    vector<pair<int,string> > vs;

    fori(i,1,n)
    {
      cin >> b >> str;
      vs.pb(mk(b,str));
    }

    map<ll,ll> mp;
    for (auto x : vs)
    {
      set<ll> st;
      if (x.fs == -1)   //traverse through all bases (2-32)
      {
        fori(i,2,36)
        {
          st.insert(ansCalculator(i,x.sc));
        }
      }
      else
      {
        st.insert(ansCalculator(x.fs, x.sc));
      }
      for (auto p : st)
        mp[p] += 1;
    }

    //traverse through the map to find out if some number
    //occured in all the n cases
    ll ans = -1;
    for (auto p : mp)
    {
      if (p.sc == n)
      {
        ans = p.fs;
        break;
      }
    }

    cout << ans << endl;

  }

  return 0;
}
