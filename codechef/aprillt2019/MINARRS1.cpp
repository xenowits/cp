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
    vector<long> v(n);
    fori(i,0,n-1)
    {
      cin >> v[i];
    }
    //auto it = std::max_element(v.begin(),v.end());
    ll sum = 0;
    for (int i = 0; i < 31; ++i)
    {
      ll counter = 0;
      fori(j,0,n-1)
      {
        if (v[j]&1 == 1)
          counter += 1;
        v[j] = v[j] >> 1;
      }
      sum += (min(counter,n-counter))*pow(2,i);
    }
    cout << sum << endl;
    t-=1;
  }
  return 0;
}
