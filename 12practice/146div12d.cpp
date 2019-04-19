#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define vp vector<pair<long,long> >

class s{
public:
    int id;
    ll l,r;
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;ll a,b;
  cin >> n;
  vector<s> arr(n+1);
  ll mina = INT_MAX, maxb = INT_MIN;
  fori(i,1,n)
  {
    cin >> a >> b;
    arr[i].id = i;
    arr[i].l = a;
    arr[i].r = b;
    if (a < mina)
      mina = a;
    if (b > maxb)
      maxb = b;
  }
  fori(i,1,n)
  {
    if (arr[i].l == mina && arr[i].r == maxb)
    {
      cout << arr[i].id;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
