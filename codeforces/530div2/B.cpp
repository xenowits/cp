#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

//vector<int> v(mod);
unordered_map<ll,ll> umap;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  ll t = (int)sqrt(n);
  //cout << t << endl;
  fori(i,t,n)
  {
    ll a = i*i;
    ford(j,a,a-i+1)
    {
      if (j == n)
      {
        cout << 2*i << endl;
        return 0;
      }
    }
    //umap[j] = 2*i;
    ll b = i*(i+1);
    ford(j,b,b-i+1)
    {
      if (j == n)
      {
        cout << 2*i+1 << endl;
        return 0;
      }
    }
    //umap[j] = 2*i+1;
  }
  //cout << umap[a] << endl;
  return 0;
}
