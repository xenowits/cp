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

struct line{
  ll x1, y1, x2, y2;
  line(ll x1, ll x2, ll x3, ll x4) : x1(x1), y1(x2), x2(x3), y2(x4){}
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll p, q, r, s;

  vector<line> xwale, ywale;

  fori(i,1,4)
  {
    cin >> p >> q >> r >> s;
    if (p == r)
    {
      xwale.emplace_back(p,q,r,s);
    }
    else if (q == s)
    {
      ywale.emplace_back(p,q,r,s);
    }
    else if (p == r && q == s)
    {
      //we don't want line to degenerate into a point
       cout << "NO" << endl;
       exit(0);
    }
    else
    {
      // if the line is not parallel to any axis
      cout << "NO" << endl;
      exit(0);
    }
  }
  bool truth = 0;
  if (xwale.size() != 2 || ywale.size() != 2 || xwale[0].x1 == xwale[1].x1 || ywale[0].y1 == ywale[1].y1)
  {
    // all four sides of rectangle not found SEPARATELY, there should be 2 X lines and 2 Y lines
    cout << "NO" << endl;
    exit(0);
  }
  else
  {
    ll x1 = min(xwale[0].x1, xwale[1].x1);
    ll x2 = max(xwale[0].x1, xwale[1].x1);
    ll y1 = min(ywale[0].y1, ywale[1].y1);
    ll y2 = max(ywale[0].y1, ywale[1].y1);
    ll area = (x2-x1)*(y2-y1);

    ll p = abs(xwale[0].y1 - xwale[0].y2);
    ll q = abs(ywale[0].x1 - ywale[0].x2);

    ll areabig = p*q;

    //areabig is the area formed if rectangle were created out of the four segments
    //area is common intersection area of rectangle
    
    //cout << area << " " << areabig << endl;
    if (area == areabig)
    {
      cout << "YES" << endl;
      exit(0);
    }
    cout << "NO" << endl;
  }

  return 0;
}
