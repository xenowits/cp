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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, ans = 0;
  cin >> n;

  map<string,ll> mp;

  fori(i,1,n)
  {
    string str;
    cin >> str;
    vector<int> cnt(26,0);
    for(char c : str)
      cnt[c-'a'] += 1;
    str.clear();
    fori(i,0,25)
    {
      if ((cnt[i]&1) == 0)
        str.pb('0');
      else
        str.pb('1');
    }
    mp[str] += 1;
  }

  string str;

  for (auto it = mp.begin(); it != mp.end(); ++it)
  {
    //cout << it->first << " " << it->second << endl;
    str = it->first;
    int cntr = 0;
    fori(i,0,25)
    {
      if (str[i] == '1')
      {
        string temp = str;
        temp[i] = '0';
        ans += mp[temp]*(it->second);
        cntr += 1;
      }
    }
    ans += mp[str]*(mp[str]-1)/2;
  }
  
  cout << ans << endl;

  return 0;
}
