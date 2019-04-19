#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

long arr[100001];
vector<ll> v[100001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k,m;
  cin >> n >> k >> m;
  fori (i,1,n)
  {
      cin >> arr[i];
      v[arr[i]%m].pb(arr[i]);
  }
  if ( n == k )
  {
    ll tem = arr[1]%m;
    fori(i,2,n)
      if (arr[i]%m != tem)
      {
          cout << "No";return 0;
      }
    cout << "Yes" << endl;
    fori(i,1,n)
      cout << arr[i] << " ";
    return 0;
  }
  fori (i,0,m-1)
  {
    //cout << "baharo " << i << " " << v[i].size() << endl;
    if (v[i].size() >= k)
    {
      //cout << i << endl;
      cout << "Yes" << endl;
      // for (auto x : v[i])
      //   cout << x <<  " ";
      for (ll j = 0; j < k ; ++j)
        cout << v[i][j] << " ";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
