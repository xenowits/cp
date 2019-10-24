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
#define MAXN (ll)1e6

vector<int> adj[MAXN];
vector<ll> c1(MAXN), c2(MAXN), c3(MAXN);

bool degreeCheck(ll n)
{
  fori(i,1,n)
  {
    if (adj[i].size() > 2)
      return 0;
  }
  return 1;
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

void calcTempCost(vector<int> &v, ll &ans)
{
  int a = v[0], b = v[1], c = v[2];
  if (a == 1)
    ans += c1[1];
  else if (a == 2)
    ans += c2[1];
  else if (a == 3)
    ans += c3[1];

  if (b == 1)
    ans += c1[2];
  else if (b == 2)
    ans += c2[2];
  else if (b == 3)
    ans += c3[2];

  if (c == 1)
    ans += c1[3];
  else if (c == 2)
    ans += c2[3];
  else if (c == 3)
    ans += c3[3];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,u,v;
  cin >> n;

  fori(i,1,n)
    cin >> c1[i];
  fori(i,1,n)
    cin >> c2[i];
  fori(i,1,n)
    cin >> c3[i];

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

  ll total_cost = INT_MAX;
  vector<ll> ans_vector;

  for(auto x : options)
  {
    ll temp_cost = 0, last_one = x[2], last_two = x[1];
    //temp_cost += (c1[x[0]]+c2[x[1]]+c3[x[2]]);
    calcTempCost(x,temp_cost);

    vector<ll> temp_vector;
    temp_vector.pb(x[0]);
    temp_vector.pb(x[1]);
    temp_vector.pb(x[2]);
    //cout << temp_cost << endl;
    fori(i,4,n)
    {
      int which_color = nextColor(last_two, last_one);

      if (which_color == 1)
      {
        temp_cost += c1[i];
        last_two = last_one;
        last_one = which_color;
        temp_vector.pb(which_color);
      }
      else if (which_color == 2)
      {
        temp_cost += c2[i];
        last_two = last_one;
        last_one = which_color;
        temp_vector.pb(which_color);
      }
      else if (which_color == 3)
      {
        temp_cost += c3[i];
        last_two = last_one;
        last_one = which_color;
        temp_vector.pb(which_color);
      }
    }

    // cout << temp_cost << endl;
    // for(auto y : temp_vector)
    //   cout << y << " ";
    // cout << endl;

    if (temp_cost < total_cost)
    {
      total_cost = temp_cost;
      ans_vector = temp_vector;
    }

    //total_cost = min(total_cost,temp_cost);
  }

  cout << total_cost << endl;
  for(auto x : ans_vector)
    cout << x << " ";

  return 0;
}
