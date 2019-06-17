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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t>0)
  {
    int d;
    string s;
    cin >> d >> s;
    int total_present = 0, required, proxy_possibility = 0;
    fori(i,0,d-1)
    {
      if (s[i] == 'P')
        total_present += 1;
      if (i >= 2 && i < d-2 && s[i] == 'A' && ((s[i-1] == 'P' || s[i-2] == 'P') && (s[i+1] == 'P' || s[i+2] == 'P')) )
      {
        proxy_possibility += 1;
      }
    }
    required = (d%4 == 0) ? (3*d)/4 : int(0.75*d)+1;
    required = required - total_present;
    if (required < 0)
      cout << 0 << endl;
    else if (proxy_possibility >= required)
    {
      cout << required << endl;
    }
    else
      cout << -1 << endl;
    t-=1;
  }
  return 0;
}
