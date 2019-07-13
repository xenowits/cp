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
  int t;
  cin >> t;
  while (t>0)
  {
    int r,c;
    char temp;
    cin >> r >> c;
    vector<char> mat[r+1][c+1];
    fori(i,1,r)
    {
      fori(j,1,c)
      {
        cin >> temp;
        mat[i][j].pb(temp);
      }
    }
    ll ans = 0;
    fori(t,1,50)
    {
      fori(i,1,r)
      {
        fori(j,1,c)
        {
          if (find(mat[i][j].begin(), mat[i][j].end(),'#') != mat[i][j].end())
            continue;
          for(char x : mat[i][j])
          {
            if (x == 'U')
            {
              if (i>1 && find(mat[i-1][j].begin(), mat[i-1][j].end(),'#') == mat[i-1][j].end())
              {
                mat[i-1][j].pb(x);
              }
            }
            else if (x == 'D')
            {
              if (i < r && find(mat[i+1][j].begin(), mat[i+1][j].end(),'#') == mat[i+1][j].end())
                mat[i+1][j].pb(x);
            }
            else if (x == 'L')
            {
              if (j>1 && find(mat[i][j-1].begin(), mat[i][j-1].end(),'#') == mat[i][j-1].end())
                mat[i][j-1].pb(x);
            }
            else if (x == 'R')
            {
              if (j < c &&  std::find(mat[i][j+1].begin(), mat[i][j+1].end(),'#') == mat[i][j+1].end())
                mat[i][j+1].pb(x);
            }
          }
          mat[i][j].clear();
        }
      }
      fori(i,1,r)
      {
        fori(j,1,c)
        {
          if (find(mat[i][j].begin(), mat[i][j].end(),'#') != mat[i][j].end())
            continue;
          int cnt = 0;
          for(char x : mat[i][j])
          {
            if (x == 'U')
            {
              cnt += 1;
            }
            else if (x == 'D')
            {
              cnt += 1;
            }
            else if (x == 'L')
            {
              cnt += 1;
            }
            else if (x == 'R')
            {
              cnt += 1;
            }
          }
          ans += (cnt*(cnt-1))/2;
        }
      }
    }
    cout << ans << endl;
    t-=1;
  }
  return 0;
}
