#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n;
  cin >> t;
  while (t>0)
  {
    cin >> n;
    vector<ll> d(n);
    fori(i,0,n-1)
      cin >> d[i];
    if (n&1)  // perfect square
    {
      set<ll> ss;
      fori(i,0,n/2)
      {
        ss.push(ss[i]*ss[n-1-i]);
      }
      if (ss.size() == 1)
      {
        cout << ss[0] << endl;
      }
      else
        cout << -1 << endl;
    }
    else
    {
      set<ll> ss;
      fori(i,0,n/2-1)
      {
        ss.push(ss[i]*ss[n-1-i]);
      }
      if (ss.size() == 1)
      {
        cout << ss[0] << endl;
      }
      else
        cout << -1 << endl;
    }
  }
  return 0;
}
