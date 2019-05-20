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
  int t,n;
  cin >> t;
  while (t>0)
  {
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<long> suffa(n);
    vector<long> suffb(n);
    fori(i,0,n-1)
    {
      cin >> a[i];
      if (i == 0)
        suffa[i] = a[i];
      else
        suffa[i] = a[i] + suffa[i-1];
    }
    fori(i,0,n-1)
    {
      cin >> b[i];
      if (i == 0)
        suffb[i] = b[i];
      else
        suffb[i] = b[i] + suffb[i-1];
    }
    ll profit = 0;
    int i;
    ll totala = suffa[n-1], totalb = suffb[n-1];
    if (totala < totalb)
    {
      cout << totalb << endl;
      t-=1;
      continue;
    }
    else if (totala > totalb)
    {
      cout << totala << endl;
      t -= 1;
      continue;
    }
    for(i = 1; i < n ; ++i)
    {
      if (totala - suffa[i-1] < totalb - suffb[i-1])
      {
        break;
      }
    }
    profit = totalb - suffb[i-1] + suffa[i-1];
    cout << profit << endl;
    t-=1;
  }
  return 0;
}
