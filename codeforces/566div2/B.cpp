#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h,w;
  cin >> h >> w;
  char mat[h+1][w+1];
  fori(i,1,h)
  {
    fori(j,1,w)
    {
      cin >> mat[i][j];
    }
  }
  int how_many = 0;
  fori(i,2,h-1)
  {
    fori(j,2,w-1)
    {
      if (mat[i][j] == '*' && mat[i-1][j] == '*' && mat[i+1][j] == '*' && mat[i][j+1] == '*' && mat[i][j-1] == '*')
      {
        how_many += 1;
        if (how_many > 1)
        {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  if (how_many == 1)
  {
    fori(i,1,h)
    {
      fori(j,1,w)
      {
        bool ans = false, ghusa = false;
        if (mat[i][j] == '*')
        {
          ghusa = true;
          if (i>1 && mat[i-1][j] == '*')
            ans = true || ans;
          if (j>1 && mat[i][j-1] == '*')
            ans = true || ans;
          if (i<h && mat[i+1][j] == '*')
            ans = true || ans;
          if (j<w && mat[i][j+1] == '*')
            ans = true || ans;
        }
        if (!ans && ghusa)
        {
          cout << "N0" << endl;
          return 0;
        }
      }
    }
    cout << "YES" << endl;
  }
  else
    cout << "NO" << endl;
  return 0;
}
