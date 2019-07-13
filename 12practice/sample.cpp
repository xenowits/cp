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
#define pi pair<int,int>
#define s second
#define f first

vector<bool> visited(20005,false);
ll n,m,ans = INT_MAX;
//vector<ll> dp(200005,0);

void bfs(int a, ll steps)
{
  visited[a] = 1;
  //cout << a << " and steps " << steps << endl;
  queue<pi> q;
  q.push(mk(a,0));
  while (!q.empty())
  {
    pi t = q.front();
    //cout << t.f << " " << t.s << endl;
    q.pop();
    if (t.f > m)
    {
      ans = min(ans,t.s+t.f-m);
      continue;
    }
    if (t.f == m)
    {
      long long topu = t.s;
      ans = min(topu,ans);
      continue;
    }
    if (t.f == 0)
      continue;
    if (!visited[t.f-1])
    {
      visited[t.f-1] = 1;
      q.push(mk(t.f-1,t.s+1));
    }
    if (!visited[2*t.f])
    {
      visited[2*(t.f)] = 1;
      q.push(mk(2*t.f,t.s+1));
    }
  }

  if (a == 0)
    return;
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  bfs(n,0);
  cout << ans << endl;
  return 0;
}
