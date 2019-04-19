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
  int n,m;
  cin >> n >> m;
  vector<ll> v(m+1);
  fori(i,1,m)
    cin >> v[i];
  ll count = 0;
  fori(i,1,m-1)
  {
    if (v[i+1] >= v[i])
    {
      count += v[i+1] - v[i];
      //cout << i << " " << v[i+1] - v[i] << " ah "<<endl;
    }
    else
    {
      count += n-v[i] + v[i+1];
      //cout << i << " " << n-v[i]+v[i+1] << " ja " << endl;
    }
  }
  // if (v[m] >= v[1])
  //   count += n - v[m] + v[1];
  // else
  //   count << v[1] - v[m];
  cout << count+v[1]-1;
  return 0;
}
