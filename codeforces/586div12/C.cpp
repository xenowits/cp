#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  vector<int> cnt(26,0);
  ll n = s.length();
  fori(i,0,n-1)
  {
    if (i == 0)
    {
      cout << "Mike" << endl;
      cnt[s[i]-'a'] += 1;
    }
    else
    {
      ll temp = s[i]-'a';
      bool hello = 0;
      fori(i,0,temp-1)
      {
        if (cnt[i] > 0)
        {
          hello = 1;
          break;
        }
      }
      if (hello)
      {
        cout << "Ann" << endl;
      }
      else
        cout << "Mike" << endl;
      cnt[s[i]-'a'] += 1;
    }
  }

  return 0;
}
