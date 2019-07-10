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

ll dp[4001][4001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vector<ll> b(n);
  set<int> s;
  ll initial_max = INT_MIN;
  unordered_map<int,int> up;
  fori(i,0,n-1)
  {
      cin >> b[i];
      up[b[i]] += 1;
      ll temps = up[b[i]];
      initial_max = max(initial_max,temps);
      s.insert(b[i]);
  }
  if (n == 1)
  {
    cout << 1 << endl;
    return 0;
  }
  unordered_map<int,int> umap;
  //code for normalisation
  int cnt = 1;
  for(auto a : s)
  {
    umap[a] = cnt;
    cnt += 1;
  }
  vector<ll> a(n);
  fori(i,0,n-1)
  {
    a[i] = umap[b[i]];
    //cout << a[i] << " " << b[i] << endl;
  }
  //vector normalised uptill now
  int new_int = s.size();
  vector<int> last_index(new_int+1);
  fori(i,0,n-1)
  {
    int temp = a[i];
    vector<bool> visited(n,false);
    visited[a[i]] = true;
    last_index[temp] = i;
    ford(j,i-1,0)
    {
      if (a[j] == temp)
        break;
      if (!visited[a[j]])
      {
        dp[temp][a[j]] += 1;
        visited[a[j]] = true;
      }
    }
  }
  // for(int p : last_index)
  //   cout << p << endl;
  ll row_maxu = INT_MIN,maxu_ele;
  ll final_ans = INT_MIN;
  fori(i,1,new_int)
  {
    fori(j,1,new_int)
    {
      //cout << dp[i][j] << " ";
      if (dp[i][j] > row_maxu)
      {
        row_maxu = dp[i][j];
        maxu_ele = j;
      }
    }
    //row_maxu = row_maxu*2;
    fori(j,1,new_int)
    {
      if (dp[i][j] == row_maxu)
      {
        if (last_index[i] < n-1 && last_index[j] > last_index[i])
          final_ans = max(final_ans,2*row_maxu+1);
      }
    }
    final_ans = max(final_ans,2*row_maxu);
    //cout << endl;
  }
  cout << max(final_ans,initial_max) << endl;
  return 0;
}
