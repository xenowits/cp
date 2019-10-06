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

vector<ll> hehe[20];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll sum, limit, temp, temp_cnt, rem;
  cin >> sum >> limit;
  rem = sum;

  vector<ll> cnt(20,0), ans;

  for(ll i = 1; i <= limit; ++i)
  {
    temp = i;
    temp_cnt = 0;
    while ((int)(temp&1) != 1)
    {
      temp_cnt += 1;
      temp = (temp >> 1);
    }
    cnt[temp_cnt] += 1;
    hehe[temp_cnt].pb(i);
  }
  //cout << endl;
  for(ll i = 19; i >= 0;i--)
  {
    temp = (1 << i);
    temp_cnt = cnt[i];
    ll hehe_cnt = 0;
    for(ll j = 1; j <= temp_cnt; ++j)
    {
      if (rem-temp >= 0)
      {
        hehe_cnt += 1;
        rem -= temp;
      }
      else
        break;
    }
    for(ll k = 0; k < hehe_cnt; ++k)
      ans.pb(hehe[i][k]);
  }
  
  if (rem > 0)
  {
    cout << -1 << endl;
    exit(0);
  }

  cout << ans.size() << endl;
  for(auto x : ans)
    cout << x << " ";

  return 0;
}
