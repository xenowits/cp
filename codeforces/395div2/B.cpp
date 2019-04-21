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
  int n;
  cin >> n;
  ll a[n+1];
  fori(i,1,n)
    cin >> a[i];
  fori(i,1,n-i+1)
  {
    if (i&1 == 1)
    {
      long temp = a[i];
      a[i] = a[n-i+1];
      a[n-i+1] = temp;
    }
  }
  fori(i,1,n)
    cout << a[i] << " ";
  return 0;
}
