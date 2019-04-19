#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,sum,sum1,sum2;
  cin >> n >> m;
  bool arr1[n+2][m+2];
  bool arr2[n+2][m+2];
  fori(i,1,n)
  {
    sum = 0;
    fori(j,1,m)
    {
      cin >> arr1[i][j];
      sum ^= arr1[i][j];
    }
    arr1[i][m+1] = sum;
  }
  fori(i,1,n)
  {
    sum = 0;
    fori(j,1,m)
    {
      cin >> arr2[i][j];
      sum ^= arr2[i][j];
    }
    arr2[i][m+1] = sum;
  }
  fori(i,1,n)
  {
    if (arr1[i][m+1] != arr2[i][m+1])
    {
      cout << "No";
      return 0;
    }
  }
  fori(i,1,m)
  {
    sum1 = 0, sum2 = 0;
    fori(j,1,n)
    {
      sum1 ^= arr1[j][i];
      sum2 ^= arr2[j][i];
    }
    if (sum1 != sum2)
    {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
