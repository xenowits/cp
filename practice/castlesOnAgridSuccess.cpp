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
#define fs first
#define sc second

int n;
bool visited[105][105];
vector<int> parent(10005,-1), dist(10005,0);

int point(int i, int j)
{
    return i*n+j;
}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{
    queue<pi> q;
    q.push(mk(point(startX,startY),startY));
    visited[startX][startY] = 1;
    int req = point(goalX,goalY);
    while (!q.empty())
    {
        pi temp = q.front();
        int pt = temp.first;
        int y = temp.sc;

        int x = (pt-y)/n;
        int X = x, Y = y;
        q.pop();

        int d = dist[pt];
        if (point(x,y) == req)
            return dist[req];
        while (x < n)
        {
            if (grid[x][y] == 'X')
                break;
            int p = point(x,y);
            if (!visited[x][y])
            {
            q.push(mk(p,y)); visited[x][y] = 1;parent[p] = pt, dist[p] = 1+dist[pt];
            }
            x+=1;
        }
        x = X;

        while(x>=0)
        {
            if (grid[x][y] == 'X')
                break;
            int p = point(x,y);
            if (!visited[x][y])
                q.push(mk(p,y)), visited[x][y] = 1,parent[p] = pt, dist[p] = 1+dist[pt];
            x-=1;
        }
        x = X;

        while (y < n)
        {
            if (grid[x][y] == 'X')
                break;
            int p = point(x,y);
            if (!visited[x][y])
                q.push(mk(p,y)), visited[x][y] = 1,parent[p] = pt, dist[p] = 1+dist[pt];
            y+=1;
        }
        y = Y;

        while(y >= 0)
        {
            if (grid[x][y] == 'X')
                break;
            int p = point(x,y);
            if (!visited[x][y])
                q.push(mk(p,y)), visited[x][y] = 1,parent[p] = pt, dist[p] = 1+dist[pt];
            y-=1;
        }
        y = Y;

    }
    return 1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  string str;
  vector<string> grid(n);
  fori(i,0,n-1)
  {
    cin >> str;
    grid[i] = str;
  }
  cout << minimumMoves(grid,2,42,68,12) << endl;
  return 0;
}
