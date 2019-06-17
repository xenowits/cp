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

#define PI 3.141592

double a,b,p,q;
ll n;

double f(double x)
{
  //cout << p/q << " " << x << " " << (p/q)*PI*x << endl;
  return abs(sin((p/q)*PI*x));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t>0)
  {
    cin >> a >> b >> p >> q;
    double basex = f(q/(2*p));
    //cout << basex << endl;
    if (f(a) == basex)
    {
      cout << a << endl;
      t-=1;
      continue;
    }
    ll temp1 = 2*a*p-q;
    ll temp2 = 2*q;
    if (temp1%temp2 == 0)
      n = temp1/temp2;
    else
      n = temp1/temp2+1;
    double x = ((2*n+1)*q)/(2*p);
    cout << "b and x and n " << b << " " << x << " " << n << endl;
    if (b<x)
    {
      cout << "fa and fb " << f(a) << " " << f(b) << endl;
      if (f(a) < f(b))
        cout << b << endl;
      else
        cout << a << endl;
    }
    else
    {
      cout << (int)x << endl;
    }
    t-=1;
  }
  return 0;
}
