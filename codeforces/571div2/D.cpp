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
  int n;
  cin >> n;
  vector<float> v(n+1);
  vector<ll> big(n+1),small(n+1);
  fori(i,1,n)
  {
      cin >> v[i];
      small[i] = (int)floor(v[i]);
      if (abs(v[i]-small[i]) > 0)
      {
          big[i] = small[i]+1;
      }
      else
        big[i] = v[i];
  }
  // fori(i,1,n)
  // {
  //   cout << small[i] << " " << big[i] << endl;
  // }
  // limits for positive
  ll a = 0,b = 0,c = 0, d = 0;
  vector<ll> ps, ng;
  stack<ll> pos, neg;
  fori(i,1,n)
  {
    if (small[i] > 0)
    {
      a += small[i];
      b += big[i];
    }
    else if (small[i] < -1)
    {
      c += small[i];
      d += big[i];
    }
    else if (small[i] == -1 && abs(small[i]-big[i]) == 1)
      neg.push(i);
    else if (small[i] == 0 && abs(small[i]-big[i]) == 1)
      pos.push(i);
    else if (small[i] == -1)
    {
      c -= 1; d -=1;
    }
    else if (small[i] == 0)
    {
      c += 0; d+= 0;
    }
  }
  cout << a << " " << b << endl << c << " " << d << endl;
  ll D = abs(d), C = abs(c);
  vector<ll> ans(n+1,INT_MIN);
  if (D < a)          //// negative addition
  {
    while (D<a)
    {
      //ng.push(neg.front());
      neg.pop();
      ans[neg.front()] = -1;
      D += 1;
    }
    while(!neg.empty())
    {
      ans[neg.front()] = 0;
      neg.pop();
    }
    fori(i,1,n)
    {
      if (ans[i] != INT_MIN)
        cout << ans[i] << endl;
      else if (ans[i] == INT_MIN && v[i] <= -1)
        cout << big[i] << endl;
      else if (ans[i] == INT_MIN && v[i] >= 1)
        cout << small[i] << endl;
      else if (ans[i] == INT_MIN && v[i] == 0)
        cout << 0 << endl;
    }
    return 0;
  }
  else if (D >= a && C <= a)
  {
    
  }
  if (C <= a && D <= b)
  return 0;
}
