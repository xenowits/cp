//Jai maa durge
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
#define MAXN (ll)1e12

vector<int>adj[500010];
lli arr[1000020];
vector<pair<int,lli>>update[500010];
vector<int>query[500010];
vector<pair<int,lli>>ans;
bool visited[500010];
int parent[500010];
int temp;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
//cin>>t;
while(t--){
  int n,q;
  cin>>n>>q;
  mem(query,0);
  for(int i=0;i<n-1;i++)
  {
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      adj[a].pb(b);
      adj[b].pb(a);
  }

  for(int i=0;i<n;i++)
  {
      lli a;
      cin>>a;
      update[i].pb(mp(0,a));
  }
  for(int i=1;i<=q;i++)
  {
      char c;
      cin>>c;
      if(c=='+')
      {
          int a;
          lli b;
          cin>>a>>b;
          a--;
          update[a].pb(mp(i,b));
      }
      else
      {
          int a;
          cin>>a;
          a--;
          query[a].pb(i);
      }
  }
  mem(visited,false);
  parent[0] = -1;
  visited[0]=true;
  queue<int>qu;
  qu.push(0);
  while(!qu.empty())
  {
      int temp = qu.front();
      qu.pop();
      for(auto&i:adj[temp])
      {
          if(visited[i]==false)
          {
              qu.push(i);
              visited[i]=true;
              parent[i]=temp;
          }
      }
  }
  Treebuild(0,1000019,0);
  mem(visited,false);
  temp = n;
  dfs(0,2*n+5);
  sort(ans.begin(),ans.end());
  for(auto&i:ans)
  {
      cout<<i.second<<endl;
  }
 }
 return 0;
}
