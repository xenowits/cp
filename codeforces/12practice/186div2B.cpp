#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  string s = to_string(abs(n));
  if (n < 0)
  {
    n = abs(n);
    ll a = n%10;
    ll b = n%100;
    ll c = max(a,b);
    string sub = s.substr(0,n-3);
    if (sub.length() == 0)
    {
      cout << 
    }
    cout << "-1" << sub << to_string(c);
  }
  else
  {
    ll a = n%10;
    ll b = n%100;
    ll c = max(a,b);
    string sub = s.substr(0,n-3);
    cout << sub << to_string(c);
  }
  return 0;
}
