#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define pb push_back
#define ll long long
#define MAXN 300001
#define mod (ll)1e9+7
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll hash_computation(string const& s)
{
  ll hash_val = 0, p = 31, p_pow = 1;
  for (char c : s)
  {
    hash_val = (hash_val+(c-'a'+1)*p_pow)%mod;
    p_pow = (p*p_pow)%mod;
  }
  return hash_val;
}

vector<ll> hash_vector(string const& s)
{
  ll n = s.length();
  vector<ll> v(n,0);
  ll hash_val = 0, p = 31, p_pow = 1, i = 0;
  for (char c : s)
  {
    hash_val = (hash_val+(c-'a'+1)*p_pow)%mod;
    p_pow = (p*p_pow)%mod;
    v[i] = hash_val;
    i += 1;
  }
  return v;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s, t;
  cin >> s >> t;

  ll n = t.length();

  //calculate hash of first string(s)

  vector<ll> hash_of_s = hash_vector(s);
  reverse(s.begin(), s.end());
  vector<ll> hash_of_s_reverse = hash_vector(s);
  reverse(s.begin(), s.end());

  //calculate hash of second string(t)

  vector<ll> hash_of_t = hash_vector(t);
  reverse(t.begin(), t.end());
  vector<ll> hash_of_t_reverse = hash_vector(t);
  reverse(t.begin(), t.end());

  ll ans = 0;
  vector<int> ans_v;

  fori(i,0,n)
  {
    if (i == 0 && hash_of_s_reverse[n-1] == hash_of_t_reverse[n-1])
      ans += 1, ans_v.pb(i);

    else if (i == n && hash_of_s[n-1] == hash_of_t[n-1])
      ans += 1, ans_v.pb(i);

    else if (i > 0 && i < n)
    {
      if (hash_of_s[i-1] == hash_of_t[i-1] && hash_of_s_reverse[n-i-1] == hash_of_t_reverse[n-i-1])
        ans += 1, ans_v.pb(i);
    }
  }

  cout << ans << endl;
  if (ans > 0)
  {
    for (int x : ans_v)
      cout << x+1 << " ";
  }
  
  return 0;
}
