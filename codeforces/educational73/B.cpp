#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  char mat[n][n];
  fori(i,0,n-1)
  {
    if (i%2 == 0)
    {
      fori(j,0,n-1)
      {
        if (j%2 == 0)
          mat[i][j] = 'W';
        else
          mat[i][j] = 'B';
      }
    }
    else
    {
      fori(j,0,n-1)
      {
        if (j%2 == 0)
          mat[i][j] = 'B';
        else
          mat[i][j] = 'W';
      }
    }
  }

  fori(i,0,n-1)
  {
    fori(j,0,n-1)
    {
      cout << mat[i][j];
    }
    cout << endl;
  }

  return 0;
}
