#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll l;
  cin >> l;
  string s;
  cin >> l >> s;
  if (l%2 == 1)
  {
    ll temp = l/2;
    string a = s.substr(0,temp-1);
    string b = s.substr(temp,l-1);

  }
  return 0;
}
