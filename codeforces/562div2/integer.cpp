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
#define sc second
#define fs first

vector<ll> v[5001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k,x;
  cin >> n >> k;

  for(int i = 1; i <= n; ++i)
  {
    cin >> x;
    v[x].pb(i);
  }
  vector<int> color(n+1,0);
  vector<int> visited(k+1,0);
  int coco = 1;
  for(int i = 1; i <= 5000; ++i)
  {
    //cout << i << " " << v[i].size() << endl;
    if (v[i].size() > k)
    {
      cout << "NO" << endl;
      exit(0);
    }
    for(int x : v[i])
    {
      visited[coco] = 1,color[x] = coco;
      if (coco < k)
        coco += 1;
      else
        coco = 1;
    }
  }
  fori(i,1,k)
  {
    if (!visited[i])
    {
      cout << "NO" << endl;
      exit(0);
    }
  }
  cout << "YES" << endl;
  for(int i = 1; i <= n; ++i)
    cout << color[i] << " ";

  return 0;
}
