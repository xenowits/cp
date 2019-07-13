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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t>0)
  {
    ll n,m,tmep,a;
    cin >> n >> m;
    priority_queue<pi> pq;
    fori(i,1,n)
    {
      cin >> a >> tmep;
      pq.push(mk(tmep,a));
    }
    //cout << endl;
    ll ans = pq.top().first;
    ll tt = pq.top().second;
    //cout << ans  << " ";
    while (pq.top().second == tt)
      pq.pop();
    ans += pq.top().first;
    cout << ans << endl;
    t-=1;
  }
  return 0;
}
