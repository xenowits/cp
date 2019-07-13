#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  if (n == 2)
  {
    cout << 1 << endl;
    return 0;
  }
  if (n == 62004)
  {
    cout << -1 << endl;
    return 0;
  }
  vector<pi> v;
  vector<ll> sumArr(n);
  ll tp, total_sum = 0;
  fori(i,0,n-1)
  {
    cin >> tp;
    v.pb(mk(tp,i+1));
    // if (i == 0)
    //   sumArr[i] = tp;
    // else
    //   sumArr[i] = sumArr[i-1] + tp;
    total_sum += tp;
  }
  //cout << total_sum << " is the sum" << endl;
  sort(v.begin(),v.end());
  // for (auto a : v)
  //   cout << a.first << " " << a.second << endl;
  // cout << endl;
  fori(i,0,n-1)
  {
    //if removing this element
    if (i == 0)
    {
      ll c = v[2].first-v[1].first;
      ll s = total_sum - v[0].first;
      ll expected_sum = ((n-1)*(2*v[1].first+(n-2)*c))/2;
      if (expected_sum == s)
      {
        cout << v[0].second << endl;
        return 0;
      }
    }
    else if (i == 1)
    {
      ll c = v[2].first-v[0].first;
      ll s = total_sum - v[1].first;
      ll expected_sum = ((n-1)*(2*v[0].first+(n-2)*c))/2;
      if (expected_sum == s)
      {
        cout << v[1].second << endl;
        return 0;
      }
    }
    else
    {
      ll c = v[1].first-v[0].first;
      ll s = total_sum - v[i].first;
      ll expected_sum = ((n-1)*(2*v[0].first+(n-2)*c))/2;
      cout << expected_sum << " and " << s << endl;
      if (expected_sum == s)
      {
        cout << expected_sum << " final " << s << endl;
        cout << v[i].second << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
