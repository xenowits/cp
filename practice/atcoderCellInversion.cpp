#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
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

  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s[0] == 'W' || s[2*n-1] == 'W')
  {
    cout << 0 << endl;
    exit(0);
  }
  string t = "L";
  fori(i,1,2*n-1)
  {
    if (s[i] == s[i-1])
    {
      if (t[i-1] == 'L')
        t.pb('R');
      else
        t.pb('L');
    }
    else
    {
      if (t[i-1] == 'L')
        t.pb('L');
      else
        t.pb('R');
    }
  }
  //cout << t << endl;
  vector<int> L(2*n,0), R(2*n,0);
  L[0] = 1;
  fori(i,1,2*n-1)
  {
    if (t[i] == 'L')
      L[i] = L[i-1]+1;
    else
      L[i] = L[i-1];

    if (t[i] == 'R')
      R[i] = R[i-1]+1;
    else
      R[i] = R[i-1];
  }
  // fori(i,0,2*n-1)
  //   cout << L[i] << " " << R[i] << endl;
  if (L[2*n-1] != R[2*n-1])
  {
    cout << 0 << endl;
    exit(0);
  }
  //cout << "jai shree ram" << endl;
  ll ans = 1;
  fori(i,0,2*n-2)
  {
    if (t[i] == 'R')
    {
      ans = (ans*(L[i]-R[i]+1))%mod;
    }
  }
  ford(i,n,1)
  {
    ans = (ans*i)%mod;
  }
  cout << ans << endl;
  return 0;
}
