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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll init = 0,glomin = INT_MAX;
  fori(i,0,s.length()-1)
  {
    if (s[i] == '-')
      init -= 1;
    else
      init += 1;
    if (init < glomin)
      glomin = init;
  }
  //cout << glomin << " " << init << endl;
  if (glomin < 0)
  {
    cout << -glomin + init;
  }
  else
    cout << init;
  return 0;
}
