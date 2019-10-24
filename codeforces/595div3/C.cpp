#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll unsigned long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll solve(ll n)
{
  vector<int> digits;
  ll temp = n;
  while (temp > 2)
  {
    int some = temp%3;
    // cout << temp << " " << some << " ";
    digits.pb(some);
    temp -= some;
    temp /= 3;
    // cout << temp << endl;
  }
  digits.pb(temp);
  // for(auto x : digits)
  //   cout << x << " ";
  // cout << endl;
  reverse(digits.begin(), digits.end());
  int pos = -1;
  int sz = digits.size();
  fori(i,0,sz-1)
  {
    if (digits[i] == 2)
    {
      pos = i;
      break;
    }
  }
  vector<int> answer = digits;
  int yetan = -1;
  for(int i = pos-1; i >= 0; --i)
  {
    if (digits[i] == 0)
    {
      yetan = i;
      break;
    }
  }
  if (pos != -1)
  {
    fori(i,pos,sz-1)
      answer[i] = 0;
  }

  if (yetan >= 0)
    answer[i] = 1;
  else
  {
    
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;

  while (q--)
  {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
  }
  // solve(3620);
  // solve(6561);

  return 0;
}
