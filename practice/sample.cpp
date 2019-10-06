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
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int cnt = 0, n = s.length();
    fori(i,0,n-1)
    {
      if (s[i] == '.')
        cnt += 1;
    }
    if (n-cnt >= 2)
      cout << "unsafe" << endl;
    else
      cout << "safe" << endl;
  }
  return 0;
}
