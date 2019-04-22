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
    int n;
    cin >> n;
    int arr[n+1][n+1];
    fori(i,1,n)
    {
      fori(j,1,n)
      {
        cin >> arr[i][j];
      }
    }
    bool zz = false;
    for(int i = 1; i <= n ; ++i)
    {
      bool truth = false;
      fori(j,1,n)
      {
        if (arr[i][j] == 0)
          truth = true;
      }
      if (!truth)
      {
        cout << "NO" << endl;
        zz = true;
        break;
      }
    }
    if (zz)
    {
      t-=1;
      continue;
    }
    for(int i = 1; i <= n ; ++i)
    {
      bool truth = false;
      fori(j,1,n)
      {
        if (arr[j][i] == 0)
          truth = true;
      }
      if (!truth)
      {
        cout << "NO" << endl;
        zz = true;
        break;
      }
    }
    if (!zz)
      cout << "YES" << endl;
    t-=1;
  }
  return 0;
}
