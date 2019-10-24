#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll unsigned long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<ll,ll>
#define sc second
#define fs first
#define MAXN (ll)1e6

vector<int> adj[MAXN];
ll arr[4][MAXN];
ll route;

bool degreeCheck(ll n)
{
  fori(i,1,n)
  {
    if (adj[i].size() > 2)
      return 0;
  }
  return 1;
}

ll rootFinder(vector<ll> &v, ll n)
{
  ll root, root2, root3;
  fori(i,1,n)
  {
    if (adj[i].size() == 1)
    {
      root = i;
      break;
    }
  }

  v.pb(root);
  root2 = adj[root][0];
  v.pb(root2);

  ll p = adj[root2][0], q = adj[root2][1];
  if (p != root)
    v.pb(p);
  else
    v.pb(q);
}

int nextColor(int p, int q)
{
  vector<bool> new_color(4,0);
  new_color[p] = 1;
  new_color[q] = 1;
  int which_color;
  fori(i,1,3)
  {
    if (!new_color[i])
    {
      which_color = i;
      break;
    }
  }
  return which_color;
}

void calcTempCost(ll &cost, vector<bool> &visited, vector<int> &colors, ll last_two, ll last_one)
{
  for (auto x : adj[route])
  {
    if (!visited[x])
    {
      int color = nextColor(last_two, last_one);
      cost += arr[color][x];
      last_two = last_one;
      last_one = color;
      visited[x] = 1;
      colors[x] = color;
      route = x;
      calcTempCost(cost,visited,colors,last_two,last_one);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,u,v;
  cin >> n;

  fori(j,1,3)
    fori(i,1,n)
      cin >> arr[j][i];

  fori(i,1,n-1)
  {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  if (!degreeCheck(n))
  {
    cout << -1 << endl;
    exit(0);
  }
  //brute force

  vector<vector<int> > options {
    {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}
  };

  ll total_cost = LLONG_MAX;
  vector<ll> root123;
  rootFinder(root123, n);
  vector<int> ans_vector;

  for (auto x : options)
  {
    ll temp_cost = 0, last_one = x[2], last_two = x[1];
    temp_cost += (arr[x[0]][root123[0]]+arr[x[1]][root123[1]]+arr[x[2]][root123[2]]);
    vector<bool> visited(n+1,0);
    route = root123[2];
    vector<int> temp_vector(n+1);
    temp_vector[root123[0]] = x[0];
    temp_vector[root123[1]] = x[1];
    temp_vector[root123[2]] = x[2];

    for(auto p : root123)
      visited[p] = 1;

    calcTempCost(temp_cost,visited, temp_vector, last_two,last_one);

    if (temp_cost < total_cost)
    {
      ans_vector = temp_vector;
      total_cost = temp_cost;
    }
  }

  cout << total_cost << endl;
  fori(i,1,n)
    cout << ans_vector[i] << " ";
    
  return 0;
}
