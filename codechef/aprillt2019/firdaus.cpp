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
  int t;
  cin >> t;
  while (t>0)
  {
    int n,q,x,y;
    cin >> n >> q;
    vector<long> v(n+1);
    fori(i,1,n)
      cin >> v[i];
    while (q>0)
    {
      cin >> x >> y;
      ll cost = 0;
      cout << v[y]-v[x]+ y-x << " " << y-x << endl;
      q-=1;
    }
    t-=1;
  }
  return 0;
}
