#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> cnt(27,0);
  fori(i,1,n)
  {
    string s;
    cin >> s;
    //cout << s[0] << endl;
    cnt[s[0]-'a'+1] += 1;
  }
  ll ans = 0;
  fori(i,1,26)
  {
    ll temp = cnt[i];
    //cout << temp << endl;
    ll t2 = temp/2;ll t1 = temp - temp/2;
    ans += (t2*(t2-1))/2 + (t1*(t1-1))/2;
  }
  cout << ans << endl;
  return 0;
}
