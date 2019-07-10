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

vector<ll> m_array(100001);
vector<pair<ll,ll> > adj[100001];
unordered_map<ll,ll> total_count;
vector<ll> ans(100001,-1);

void bfs(vector<bool> &visited, int a)
{
  queue<int> q;
  unordered_map<int,int> umap;
  visited[a] = true;
  q.push(a);
  //umap[a] += 1;
  if (ans[m_array[a]] != 0)
    umap[m_array[a]] += 1;

  while (!q.empty())
  {
    int t = q.front();
    // int tm = m_array[t];

    q.pop();
    for (auto b : adj[t])
    {
      if (!visited[b.first])
      {
        q.push(b.first);
        visited[b.first] = true;
        int tm = m_array[b.first];
        if (ans[tm] != 0)
        {
          umap[tm] += 1;
          if (umap[tm] == total_count[tm])
            ans[tm] = b.second;
        }
      }
    }
  }
  for (auto b : umap)
  {
    if (b.second != total_count[b.first])
    {
      ans[b.first] = 0;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,q,a,b;
  ifstream inFile;
  inFile.open("testData1.txt");
  if (!inFile)
  {
    cout << "Unable to open the file" << endl;
    exit(1);
  }
  inFile >> n >> m >> q;
  fori(i,1,n)
  {
    inFile >> m_array[i];
    total_count[m_array[i]] += 1;
  }
  fori(i,1,q)
  {
    inFile >> a >> b;
    adj[a].pb(mk(b,i));
    adj[b].pb(mk(a,i));
  }
  inFile.close();
  vector<bool> visited(n+1,false);
  int aisehi = 0;
  fori(i,1,n)
  {
    if (!visited[i])
    {
      bfs(visited,i);
      aisehi += 1;
    }
  }

  fori(i,1,m)
  {
    cout << total_count[i] << " ";
    if (total_count[i] == 1)
      cout << 0 << endl;
    else
      cout << ans[i] << endl;
  }
  cout << "total components are " << aisehi << endl;
  return 0;
}
