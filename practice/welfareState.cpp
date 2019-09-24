#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

struct query {
  int indx, type, a, b;
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> arr(n+1,0);
  fori(i,1,n)
    cin >> arr[i];

  int q;
  cin >> q;

  vector<query> queries;
  int popo = 1;
  while (popo <= q)
  {
    query haha;
    int x,y,z;
    cin >> x;
    haha.indx = popo;
    haha.type = x;
    if (x == 1)
    {
      cin >> y >> z;
      haha.a = y;
      haha.b = z;
    }
    else
    {
      cin >> y;
      haha.a = y;
      haha.b = 0;
    }
    queries.pb(haha);
    popo += 1;
  }

  reverse(queries.begin(), queries.end());

  // ans begins

  int max_so_far = 0;
  vector<bool> visited(n+1,0);

  for(auto x : queries)
  {
    if (x.type == 1 && !visited[x.a])
    {
      arr[x.a] = max(x.b,max_so_far);
      visited[x.a] = 1;
    }
    else if (x.type == 2)
      max_so_far = max(max_so_far,x.a)
  }

  fori(i,1,n)
  {
    if (!visited[i])
      arr[i] = max(arr[i], max_so_far);
    cout << arr[i] << " ";
  }

  return 0;
}
