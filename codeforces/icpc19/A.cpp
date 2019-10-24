#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define MAXN (ll)1e6+7
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll toNum(string s, int n)
{
  ll ans = 0;
  reverse(s.begin(), s.end());
  ll tti = 1;
  fori(i,0,n-1)
  {
    ans += (s[i]-'0')*tti;
    tti = tti*10;
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
  #endif

  ll t = 1;
  cin >> t;

  while (t--)
  {
    string str;
    cin >> str;
    ll n = str.length();
    vector<ll> v;
    fori(i,0,n-1)
    {
      if (i == 0)
      {
        v.pb(toNum(str.substr(1,n-1), n-1));
      }
      else if (i == n-1)
        v.pb(toNum(str.substr(0,n-1),n-1));
      else
        v.pb(toNum(str.substr(0,i)+str.substr(i+1,n-i-1), n-1));
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
  }

  return 0;
}
