#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define pi pair<long long, long long>
#define f first
#define s second

vector<ll> cocoa(10,0);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a,b,c;
  cin >> a >> b >> c;
  vector<pi> v{mk(a,1), mk(b,2), mk(c,3)};
  sort(begin(v), end(v));
  // for (auto x : v)
  //   cout << x.f << " " << x.s << endl;
  pi A = v[0];
  pi B = v[1];
  pi C = v[2];
  if (A.f != B.f && B.f == C.f)
  {
    cout << "Impossible" << endl;
  }
  else
  {
    if (A.f < B.f)
    {
      cocoa[B.s+C.s] = (B.f-A.f);
      C.f -= (B.f-A.f);
      B.f = A.f;
    }
    //cout << A.f << " " << B.f << " "<< C.f << endl;
    if (C.f%2 != 0)
    {
      cout << "Impossible" << endl;
      exit(0);
    }
    ll tp = C.f/2;
    A.f -= tp; B.f -= tp;
    //cout << A.f << " " << B.f << " "<< C.f << endl;
    cocoa[A.s+C.s] += tp;
    //cout << B.s << " df " << C.s << " " << cocoa[B.s+C.s] << endl;
    cocoa[B.s+C.s] = cocoa[B.s+C.s] + tp;

    // yeha tk c ka kaam kthm hua
    if (A.f < 0)
    {
      cout << "Impossible" << endl;
      exit(0);
    }
    if (A.f == B.f)
      cocoa[A.s+B.s] = A.f;
    cout << cocoa[3] << " "<< cocoa[5] << " " << cocoa[4] << endl;
  }
  return 0;
}
