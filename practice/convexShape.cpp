#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

int n,m;
char ch[52][52];
int size;

void solve(pi cell)
{
  bool visited[n+1][m+1];
  fori(i,1,n)
    fori(j,1,m)
      visited[i][j] = 0;
  queue<pi> q;
  q.push(cell);
  visited[cell.fs][cell.sc] = 1;
  int cntr = 1;
  while (!q.empty() && cntr < 3)
  {
    int sz = q.size();
    fori(i,1,sz)
    {
      pi temp = q.front();
      q.pop();
      int x = temp.fs, y = temp.sc;
      fori(i,x+1,n)
      {
        if (ch[i][y] == 'W')
          break;
        else
        {
          visited[i][y] = 1;
          q.push(mk(i,y));
        }
      }
      ford(i,x-1,1)
      {
        if (ch[i][y] == 'W')
          break;
        else
        {
          visited[i][y] = 1;
          q.push(mk(i,y));
        }
      }
      fori(j,y+1,m)
      {
        if (ch[x][j] == 'W')
          break;
        else
        {
          visited[x][j] = 1;
          q.push(mk(x,j));
        }
      }
      ford(j,y-1,1)
      {
        if (ch[x][j] == 'W')
          break;
        else
        {
          visited[x][j] = 1;
          q.push(mk(x,j));
        }
      }
    }
    cntr += 1;
  }
  cntr = 0;
  fori(i,1,n)
  {
    fori(j,1,m)
    {
      if (visited[i][j])
        cntr += 1;
    }
  }
  if (cntr != size)
  {
    cout << "NO" << endl;
    exit(0);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  stack<pi> stk;
  cin >> n >> m;
  fori(i,1,n)
  {
    fori(j,1,m)
    {
      cin >> ch[i][j];
      if (ch[i][j] == 'B')
        stk.push(mk(i,j));
    }
  }
  size = stk.size();
  //cout <<size << endl;
  while (!stk.empty())
  {
    pi cell = stk.top();
    stk.pop();
    solve(cell);
  }
  cout << "YES" << endl;
  return 0;
}
