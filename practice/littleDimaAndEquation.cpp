#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000000
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll f(ll x)
{
  ll sum = 0;
  while (x > 0)
  {
    sum += x%10;
    x /= 10;
  }
  return sum;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a,b,c,temp;
  cin >> a >> b >> c;
  vector<ll> v;

  fori(i,1,99)
  {
    temp = b*((ll)pow(i,a)) + c;
    if (f(temp) == i && temp < mod)
      v.pb(temp);
    //cout << f(temp) << " " << temp << " " << i << endl;
  }

  cout << v.size() << endl;
  if (v.size())
  {
    fori(i,0,v.size()-1)
      cout << v[i] << " ";
  }
  return 0;
}
