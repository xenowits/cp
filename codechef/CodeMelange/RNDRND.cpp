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
  vector<int> v(m);
  fori(i,0,m-1)
    cin >> v[i];
  int sizu = m;
  vector<int> minos;
  fori(x,1,n-1)
  {
    int indx = 1,gobali = 0,abtak = 0;
    while(1)
    {
      if (indx == v[gobali])
      {
        gobali += 1;
      }
      cout << indx+x << endl;
      indx = (indx+x)%n;
      if (indx % n == 0)
        indx = n;
      else
        indx = (indx+x)%n;
      abtak += 1;
      cout << indx << " " << v[gobali] << " " << gobali << " " << x << endl;
      //return 0;
      if (gobali == sizu - 1)
        break;
    }
    minos.pb(abtak);
  }
  auto it = std::min_element(minos.begin(),minos.end());
  cout << *it;
  return 0;
}
