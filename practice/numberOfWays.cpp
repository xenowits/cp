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

void print(multiset<ll> mset)
{
  for (int x :  mset)
    cout << x << " ";
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> v(n+1,0), presum(n+1);
  std::unordered_multiset<ll> mset;

  fori(i,1,n)
  {
    cin >> v[i];
    presum[i] = presum[i-1] + v[i];
    mset.insert(presum[i]);
  }
  if (presum[n]%3 != 0)
  {
    cout << 0 << endl;
    return 0;
  }

  auto x = mset.find(presum[n]);
  mset.erase(x);

  ll ans = 0, sum = 0;

  ford(j,n-1,3)
  {
    auto it = mset.find(presum[j]);
    mset.erase(it);
    sum += v[j+1];
    if (presum[j] == 2*sum)
    {
      ans += mset.count(sum);
    }
    if (mset.empty())
      break;
  }

  if (v[1] == v[2] && v[2] == sum)
  {
    ans += 1;
  }
  cout << ans << endl;
  return 0;
}
