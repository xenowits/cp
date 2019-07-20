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
#define pi pair<int,int>
#define sc second
#define fs first

bool cmp(string s, string t)
{
  int j = 0;
  int m = s.length();
  int n = t.length();
  for(int i = 0 ; i < n && j < m; i++)
    if (s[j] == t[i])
      j++;
  return (j == m);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll q;
  cin >> q;
  while (q)
  {
    string s,t,p;
    cin >> s >> t >> p;
    vector<ll> cnts(27,0), cntp(27,0), cntt(27,0);
    fori(i,0,s.length()-1)
    {
      cnts[s[i]-'a'] += 1;
    }
    fori(i,0,p.length()-1)
      cntp[p[i]-'a'] += 1;
    bool truth = 0;
    if (!cmp(s,t))
    {
      cout << "NO" << endl;
    }
    else
    {
      fori(i,0,t.length()-1)
      {
        cntt[t[i]-'a'] += 1;
      }
      fori(i,0,25)
      {
        cntt[i] -= cnts[i];
      }
      fori(i,0,25)
      {
        if (cntp[i] < cntt[i])
        {
          truth = 1;
          break;
        }
      }
      if (truth)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
    q-=1;
  }
  return 0;
}
