#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

char mat[51][51];
int parx[51][51], pary[51][51];
int n,m;
int color[51][51];
bool ans = 0;
char ch;
vector<pi> v[27];

void init()
{
  fori(i,0,n)
    fori(j,0,m)
      color[i][j] = 0, parx[i][j] = -1, pary[i][j] = -1;
  ans = 0;
}

void dfs(int a, int b)
{
  color[a][b] = 1;
  //cout << a << " dfs values " << b << " " << parx[a][b] << " " << pary[a][b] << endl;
  // int ax = min(a+1,n-1), bx = min(b+1,m-1), ay = max(a-1,0), by = max(b-1,0);
  // if (color[ax][b] == 1 || color[ay][b] == 1 || color[a][bx] == 1 || color[a][by] == 1)
  // {
  //   ans = 1;
  //   cout << a << " ans h " << b << endl;
  // }
  if (a < n-1 && color[a+1][b] == 1 && !(parx[a][b] != a+1 && pary[a][b] != b))
  {
    ans = 1;
    //cout << a-1 << " first " << b  << endl;
  }
  if (b < m-1 && color[a][b+1] == 1  && !(parx[a][b] != a && pary[a][b] != b+1))
  {
    ans = 1;
    //cout << a << " second " << b+1  << endl;
  }
  if (a > 0 && color[a-1][b] == 1 && !(parx[a][b] == a-1 && pary[a][b] == b))
  {
    ans = 1;
    //cout << a-1 << " third " << b << " " << parx[a-1][b] << " " << pary[a-1][b] <<  endl;
  }
  if (b > 0 && color[a][b-1] == 1 && !(parx[a][b] == a && pary[a][b] == b-1))
  {
    ans = 1;
    // cout << a << " " << b << " h na " << a << " fourth " << b-1 << " " << parx[a][b-1] << " " << pary[a][b-1] << endl;
  }
  //cout << a << " " << b << " h na " << a << " fourth " << b-1 << " " << parx[a][b] << " " << pary[a][b] << endl;
  if (a < n-1 && color[a+1][b] == 0 && mat[a+1][b] == ch)
  {
    parx[a+1][b] = a, pary[a+1][b] = b;
    dfs(a+1,b);
  }
  if (b < m-1 && color[a][b+1] == 0 && mat[a][b+1] == ch)
  {
    parx[a][b+1] = a, pary[a][b+1] = b;
    //cout << a << " " << b << " " << parx[a][b+1] << " jio " << pary[a][b+1] << endl;
    dfs(a,b+1);
  }
  if (a > 0 && color[a-1][b] == 0 && mat[a-1][b] == ch)
  {
    parx[a-1][b] = a, pary[a-1][b] = b;
    dfs(a-1,b);
  }
  if (b > 0 && color[a][b-1] == 0 && mat[a][b-1] == ch)
  {
    parx[a][b-1] = a, pary[a][b-1] = b;
    dfs(a,b-1);
  }
  //color[a][b] = 2;
  // if (ans)
  //   cout << a << " kaise hua " << b << endl;
}

int main()
{

  cin >> n >> m;

  for(int i = 0; i < n; i++)
  {
    for (int j = 0 ; j < m; ++j)
    {
      cin >> mat[i][j];
      v[mat[i][j]-'A'].pb(mk(i,j));
    }
  }
  for (char p = 'A'; p <= 'Z'; ++p)
  {
    init();
    ch = p;
    for(auto x : v[p-'A'])
    {
      //cout << ch << endl;
      if (color[x.fs][x.sc] == 0)
        dfs(x.fs,x.sc);
      if (ans)
      {
        cout << "Yes " << endl;
        exit(0);
      }
      //cout << endl << endl << endl;
    }
  }
  cout << "No" << endl;
  return 0;
}
