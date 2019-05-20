#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define md 998244353

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,temp;
  cin >> n;
  // if (n == 100)
  // {
  //   cout << 726263105;
  //   return 0;
  // }
  vector<ll> b(n);
  vector<pair<ll,ll> > a;
  fori(i,0,n-1)
  {
    cin >> temp;
    a.pb(mk(temp,i));
  }
  fori(i,0,n-1)
    cin >> b[i];
  vector<ll> auxiliary(n);
  fori(i,0,n-1)
  {
    auxiliary[i] = (i+1)*(n-i);
    //cout << auxiliary[i] << " ";
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end(),greater<int>());
  //cout << endl;
  ll cnt = 0;
  fori(i,0,n-1)
  {
    //cout << auxiliary[a[i].second]*(a[i].first)*b[i] << " ";
    cnt = (cnt + (((( auxiliary[a[i].second]%md*(a[i].first))%md)*b[i])%md )%md);
  }
  //cout << endl;
  cout << cnt;
  return 0;
}
