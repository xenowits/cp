#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

vector<int> rabin_karp(string const& s, string const& t)
{
  const int p = 31;
  const int m = 1e9 + 9;
  int S = s.size(), T = t.size();

  vector<ll> p_pow(max(S, T));
  p_pow[0] = 1;
  for (int i = 1; i < (int) p_pow.size(); ++i)
    p_pow[i] = (p_pow[i-1]*p)%m;

  vector<ll> h(T+1, 0);
  for(int i = 0 ; i < T; ++i)
    h[i+1] = (h[i] + (t[i]-'a'+1)*p_pow[i])%m;
  ll h_s = 0;
  for (int i = 0; i < S ; ++i)
    h_s = (h_s + (s[i]-'a'+1)*p_pow[i])%m;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
