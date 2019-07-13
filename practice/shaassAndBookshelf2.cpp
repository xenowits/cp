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
  int n,a,b;
  cin >> n;
  vector<int> ones, twos;
  ll presum = 0;
  fori(i,1,n)
  {
    cin >> a >> b;
    presum += b;
    if(a==1)
      ones.pb(b);
    else
      twos.pb(b);
  }
  ll no_twos = twos.size(), no_ones = ones.size();
  sort(ones.begin(), ones.end(), greater<int>());
  sort(twos.begin(), twos.end(), greater<int>());

  vector<ll> preOnesum(no_ones+1,0);
  fori(i,1,no_ones)
  {
    preOnesum[i] = ones[i-1] + preOnesum[i-1];
  }
  vector<ll> preTwosum(no_twos+1,0);
  fori(i,1,no_twos)
  {
    preTwosum[i] = twos[i-1] + preTwosum[i-1];
  }
  // for(int x : preOnesum)
  //   cout << x << " ";
  // cout << endl;
  // for (int x : preTwosum)
  //   cout << x << " ";
  // cout << endl;
  ll ans = INT_MAX;
  fori(j,0,no_twos)     /// no of twos
  {
    fori(i,0,no_ones)       /// no of ones
    {
      ll t = i+2*j;
      ll sum = presum - ( preOnesum[i] + preTwosum[j] );
      if (t >= sum)
        ans = min(ans,t);
    }
  }
  cout << ans << endl;
  return 0;
}
