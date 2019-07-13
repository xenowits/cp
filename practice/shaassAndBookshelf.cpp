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
  vector<pi> v;
  fori(i,1,n)
  {
    cin >> a >> b;
    v.pb(mk(a,b));
  }
  sort(v.begin(), v.end(), [] (pi x, pi y) -> bool
  {
    if (x.second != y.second)
      return x.second > y.second;
    else
    {
      return (x.first < x.second);
    }
  });
  ll presum = 0;
  cout << "bhai bhai bhai" << endl;
  for (auto x : v)
  {
    cout << x.first << " " << x.second << endl;
    presum += x.second;
  }
  //cout << presum << endl;
  /// main algo starts here
  ll curr_width = 0,i = 0;
  while (curr_width < presum)
  {
    curr_width += v[i].first;
    presum -= v[i].second;
    i += 1;
    cout << i << " " << curr_width << " " << presum << endl;
    if (curr_width - presum == 0)
    {
      cout << curr_width << endl;
      return 0;
    }
    else if (curr_width - presum > 0)
    {
      i-=1;
      curr_width -= v[i].first;
      presum += v[i].second;
      break;
    }
  }
  cout << "dikkt yeha h " << v[i].first << " " << v[i].second << " diff " << curr_width-presum << endl;
  cout << curr_width << " " << presum << endl;
  fori(j,i+1,n-1)
  {
    if (v[j].first == 1 && (curr_width+1-(presum-v[j].second) >= 0) )
    {
      cout << curr_width + 1 << endl;
      return 0;
    }
  }
  cout << curr_width + 2 << endl;
  return 0;
}
