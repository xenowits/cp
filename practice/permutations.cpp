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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v1(n+1), v2(n+1), v3(n+1);
  unordered_map<int,int> umap;

  fori(i,1,n)
    cin >> v1[i];
  fori(i,1,n)
  {
    cin >> v2[i];
    umap[v2[i]] = i;
  }
  fori(i,1,n)
  {
    v3[i] = umap[v1[i]];
    //cout << v3[i] << " ";
  }
  //cout << endl;
  int i;
  for(i = 2; i <= n; ++i)
  {
    if (v3[i] < v3[i-1])
      break;
  }
  //cout << i << endl;
  cout << n-i+1 << endl;
  return 0;
}
