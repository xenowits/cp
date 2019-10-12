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
  vector<int> f(m+1);
  fori(i,1,m)
    cin >> f[i];
  sort(f.begin(),f.end());
  long minu = INT_MAX;
  fori(i,1,m)
  {
    if (f[i+n-1] - f[i] < minu && i+n-1 <= m)
      minu = f[i+n-1] - f[i];
  }
  cout << minu;
  return 0;
}
