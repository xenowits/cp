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
  string x;
  cin >> n >> x;
  reverse(x.begin(),x.end());
  fori(i,0,n-1)
  {
    if (x[i] == '1')
    {
      cout << i;
      break;
    }
  }
  return 0;
}
