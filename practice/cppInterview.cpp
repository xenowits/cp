#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<iterator>

using namespace std;

#define MAXN 200005
#define ll long long int
#define pb push_back
#define mk make_pair
#define pi pair<int,int>
#define fs first
#define sc second

vector<pi > adj[MAXN];
vector<int> dist(MAXN,INT_MAX), dist1(MAXN,INT_MAX), parent(MAXN,-1);
vector<bool> ismst(MAXN,0);

void dijkstra(int s, int n)
{
  priority_queue<pi, vector<pi>, greater<pi> > q;
  dist[s] = 0;
  q.push(mk(0,s));
  while(!q.empty())
  {
    int src = q.top().sc;
    q.pop();
    vector<pi>::iterator it;
    for(it = adj[src].begin() ; it != adj[src].end() ; ++it)
    {
    // for(auto x : adj[src])
    // {
       int wt = (*it).sc, dst = (*it).fs;
      //int wt = x.sc, dst = x.fs;
      if (dist[dst] > dist[src]+wt)
      {
        dist[dst] = dist[src]+wt;
        q.push(mk(dist[dst],dst));
      }
    }
  }
  for(int i = 0; i < n; ++i)
    cout << i << " " << dist[i] << endl;
}

void prims(int s, int n)
{
  priority_queue<pi, vector<pi>, greater<pi> > q;
  q.push(mk(0,s));
  ismst[s] = 1;
  dist1[s] = 0;
  while(!q.empty())
  {
    int src = q.top().sc;
    q.pop();
    for (auto x : adj[src])
    {
      int wt = x.fs, dst = x.sc;
      if (!ismst[dst] && wt < dist1[dst])
      {
        dist1[dst] = wt;
        parent[dst] = src;
        q.push(mk(wt,dst));
      }
    }
    ismst[src] = 1;
  }
  for(int i = 0 ; i < n; ++i)
  {
    cout << i << " " << parent[i] << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  //dijkstra's algorithm for SSSP
  long n,e,x,y,wt;

  cin >> n >> e;
  for(int i = 1; i <= e; ++i)
  {
    cin >> x >> y >> wt;
    adj[x].pb(mk(y,wt));
    adj[y].pb(mk(x,wt));
  }
  int source;
  cout << "enter source now" << endl;

  cin >> source;

  //dijkstra(source,n);

  prims(source,n);

  return 0;
}
/*
9
14
0 1 4
0 7 8
1 7 11
1 2 8
7 6 1
7 8 7
2 8 2
6 8 6
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
4 5 10
*/
