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
    vector<int> v(n);
    fori(i,0,n-1)
    {
      cin >> v[i];
    }
    auto it = std::max_element(v.begin(),v.end());
    ll minima = INT_MAX;
    fori(i,1,*it)
    {
      ll sum = 0;
      fori(j,0,n-1)
      {
        sum += (v[j]^i);
      }
      minima = min(minima,sum);
    }
    cout << minima << endl;
    t-=1;
  }
  return 0;
}
