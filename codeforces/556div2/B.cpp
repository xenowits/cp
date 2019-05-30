#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  char arr[n+1][n+1];
  fori(i,1,n)
  {
    fori(j,1,n)
    {
      cin >> arr[i][j];
    }
  }
  fori(i,2,n-1)
  {
    fori(j,2,n-1)
    {
      if (arr[i][j] == '.' && arr[i+1][j] == '.' && arr[i-1][j] == '.' && arr[i][j+1] == '.' && arr[i][j-1] == '.' )
      {
        arr[i][j] = '#' ; arr[i+1][j] = '#'; arr[i-1][j] = '#'; arr[i][j+1] = '#'; arr[i][j-1] = '#';
      }
    }
  }
  fori(i,1,n)
  {
    fori(j,1,n)
    {
      if (arr[i][j] == '.')
      {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
