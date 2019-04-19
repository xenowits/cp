#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,t,s,d;
  cin >> n >> t;
  vector<pair<long,long> > v;
  fori(i,1,n)
  {
    cin >> s >> d;
    if (s == t)
    {
      cout << i;
      return 0;
    }
    if (s > t)
      v.pb(mk(s,i));
    else if (s < t)
    {
      if ((t-s)%d == 0)
      {
        cout << i;
        return 0;
      }
      else
      {
        v.pb(mk(s+((t-s)/d+1)*d,i));
      }
    }
  }
  sort(v.begin(),v.end());
  cout << v[0].second;
  return 0;
}
