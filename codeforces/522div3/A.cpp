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
  // long a,b,c,d;
  // cin >> a >> b >> c >> d;
  // long e = (a+b+c+d)/3;
  // if (a != e)
  //   cout << e-a << " ";
  // if (b != e)
  //   cout << e-b << " ";
  // if (c != e)
  //   cout << e-c << " ";
  // if (d != e)
  //   cout << e - d;
  unsigned long arr[5] , sum = 0;
  fori(i,1,4)
  {
    cin >> arr[i];
    sum += arr[i];
  }
  unsigned long abc = sum/3;
  vector<ll> v;
  fori(i,1,4)
  {
    if (arr[i] != abc)
      v.pb(abc-arr[i]);
  }
  for(int i = 0 ; i < 3 ; ++i)
  {
    if (i == 0 || i == 1)
      cout << v[i] << " ";
    else
      cout << v[i];
  }
  return 0;
}
