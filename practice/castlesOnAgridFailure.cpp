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

int visited[105][105];
bool acc[105][105];

//1 for horizontal and 0 for vertical

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{

    queue<pair<int,int> > q;
    visited[startX][startY] = 1;
    int n = grid.size();
    q.push(mk(startX,startY));

    while (!q.empty())
    {
        pi s = q.front();

        q.pop();

        // if (s.fs == goalX && s.sc == goalY)
        //     return visited[goalX][goalY];

        int x_t = s.fs, y_t = s.sc;

        if (x_t > 0 && grid[x_t-1][y_t] != 'X' && visited[x_t-1][y_t] == 0) //upar jana h
        {
            if (x_t == startX)
            {
                visited[x_t-1][y_t] = visited[x_t][y_t];
                acc[x_t-1][y_t] = 0;
            }
            else if (acc[x_t][y_t])
            {
                visited[x_t-1][y_t] = 1+visited[x_t][y_t];
                acc[x_t-1][y_t] = 0;
            }
            else if (!acc[x_t][y_t])
            {
                visited[x_t-1][y_t] = visited[x_t][y_t];
                acc[x_t-1][y_t] = 0;
            }
            q.push(mk(x_t-1,y_t));
        }

        if (y_t > 0 && grid[x_t][y_t-1] != 'X'  && visited[x_t][y_t-1] == 0)//left m jao
        {
            if (x_t == startX)
            {
                visited[x_t][y_t-1] = visited[x_t][y_t];
            }
            else if (acc[x_t][y_t])
            {
                visited[x_t][y_t-1] = visited[x_t][y_t];
            }
            else if (!acc[x_t][y_t])
            {
                visited[x_t][y_t-1] = 1+visited[x_t][y_t];
            }
            acc[x_t][y_t-1] = 1;
            q.push(mk(x_t,y_t-1));
        }

        if (x_t < n-1 && grid[x_t+1][y_t] != 'X'  && visited[x_t+1][y_t] == 0)//neeche ja
        {
            if (x_t == startX)
            {
                visited[x_t+1][y_t] = visited[x_t][y_t];
            }
            else if (acc[x_t][y_t])
            {
                visited[x_t+1][y_t] = 1+visited[x_t][y_t];
            }
            else if (!acc[x_t][y_t])
            {
                visited[x_t+1][y_t] = visited[x_t][y_t];
            }
            acc[x_t+1][y_t] = 0;
            q.push(mk(x_t+1,y_t));
        }

        if (y_t < n-1 && grid[x_t][y_t+1] != 'X' && visited[x_t][y_t+1] == 0) //right jaa
        {
            if (x_t == startX)
            {
                visited[x_t][y_t+1] = visited[x_t][y_t];
            }
            else if (acc[x_t][y_t])
            {
                visited[x_t][y_t+1] = visited[x_t][y_t];
            }
            else if (!acc[x_t][y_t])
            {
                visited[x_t][y_t+1] = 1+visited[x_t][y_t];
            }
            acc[x_t][y_t+1] = 1;
            q.push(mk(x_t,y_t+1));
        }

    }
    cout << "     ";
    for(int i = 0 ; i < n; ++i)
      cout << i << "  ";
    for(int i = 0 ; i < n; ++i){
      cout << i << "    ";
        for(int j = 0 ; j < n; ++j)
            cout << visited[i][j] << "  ";
        cout << endl;}
    return visited[goalX][goalY];
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string str;
  vector<string> grid(n);
  fori(i,0,n-1)
  {
    cin >> str;
    grid[i] = str;
  }
  cout << minimumMoves(grid,34,28,16,8) << endl;
  return 0;
}
