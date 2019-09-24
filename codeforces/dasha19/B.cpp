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


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,x,y;
  cin >> n;

  string s;
  cin >> s;
  vector<int> a(n), b(n);

  fori(i,0,n-1)
  {
    cin >> x >> y;
    a[i] = x;
    b[i] = y;
  }

  ll ans = 0;

  fori(i,0,100007)
  {
    ll cnt = 0;
    fori(j,0,n-1)
    {
      if (s[j] == '1')
        cnt += 1;
    }
    ans = max(ans,cnt);
    // cout << s << endl;
    // cout << ans << endl;
    fori(j,0,n-1)
    {
      if (i == b[j])
      {
        if (s[j] == '0')
          s[j] = '1';
        else
          s[j] = '0';
      }
      else if (i >= b[j] && (i-b[j])%a[j] == 0)
      {
        if (s[j] == '0')
          s[j] = '1';
        else
          s[j] = '0';
      }
    }
    // cout << s << endl;
  }

  cout << ans << endl;

  return 0;
}
