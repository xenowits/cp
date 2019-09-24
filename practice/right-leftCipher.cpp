#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.length();

  vector<char> v1, v2;

  if (n&1)
  {
    fori(i,0,n/2)
      v1.pb(s[i]);
    fori(i,n/2+1,n-1)
      v2.pb(s[i]);
    reverse(v1.begin(), v1.end());
    fori(i,0,n/2-1)
    {
      cout << v1[i] << v2[i];
    }
    cout << v1[n/2];
  }

  else
  {
    fori(i,0,n/2-1)
      v1.pb(s[i]);
    fori(i,n/2,n-1)
      v2.pb(s[i]);
    reverse(v1.begin(), v1.end());
    fori(i,0,n/2-1)
    {
      cout << v1[i] << v2[i];
    }
  }

  return 0;
}
