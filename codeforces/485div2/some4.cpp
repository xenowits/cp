#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long> s(n+1);
    vector<long> c(n+1);
    fori(i,1,n)
    {
      cin >> s[i];
    }
    fori(i,1,n)
    {
      cin >> c[i];
    }
    long dpij[n+1], dpjk[n+1];
    fori(i,1,n)
      dpij[i] = INT_MAX, dpjk[i] = INT_MAX;
    fori(i,1,n)
    {
      fori(j,1,i-1)
      {
        if (s[j] < s[i])
          dpij[i] = std::min(dpij[i], c[i]+c[j]);
      }
    }
    fori(i,1,n)
    {
      fori(j,i+1,n)
      {
        if (s[j] > s[i])
          dpjk[i] = std::min(dpjk[i], c[i]+c[j]);
      }
    }
    vector<long> a;
    fori(i,1,n)
    {
      if (dpij[i] != INT_MAX && dpjk[i] != INT_MAX)
        a.pb(dpij[i] + dpjk[i] - c[i]);
    }
    sort(a.begin(),a.end());
    if (a.empty())
    {
      cout << -1;
      return 0;
    }
    // for (int x : a)
    //   cout << x << " ";
    else
      cout << a[0];
    return 0;
}
