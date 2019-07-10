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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> v(n+1);
  ll sum = 0, max_v = INT_MIN;
  fori(i,1,n)
  {
    cin >> v[i];
    sum += v[i];
    max_v = max(max_v,v[i]);
  }
  ll rounds = (int)(ceil((sum*1.0)/(n-1)));
  //cout << sum/(n-1) << endl;
  //cout << rounds << " is the no of rounds" << endl;
  if (rounds < max_v)
    rounds = max_v;
  cout << rounds << endl;
  return 0;
}
