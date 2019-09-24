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

struct point{
  ll x,y;
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll x1,y1,x2,y2, x3,y3,x4,y4, x5,y5,x6,y6;

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

  // shifting origin to (x1,y1)

  point p1 = {(ll)0,(ll)0}, p2 = {x2-x1,y2-y1};
  point p3 = {min(x2-x1,max(x3-x1,(ll)(ll)0)),min(y2-y1,max(y3-y1,(ll)0))}, p4 = {min(x2-x1,max((ll)0,x4-x1)),min(y2-y1,max((ll)0,y4-y1))};
  point p5 = {min(x2-x1,max(x5-x1,(ll)0)),min(y2-y1,max(y5-y1,(ll)0))}, p6 = {min(x2-x1,max(x6-x1,(ll)0)),min(y2-y1,max(y6-y1,(ll)0))};

  // Area of 1st Rectangle
  ll area1 = abs(p3.x - p4.x) *
            abs(p3.y - p4.y);

  // Area of 2nd Rectangle
  ll area2 = abs(p5.x - p6.x) *
            abs(p5.y - p6.y);

  ll area = abs(p1.x - p2.x) *
            abs(p1.y - p2.y);

  ll areaI = (min(p4.x, p6.x) - max(p3.x, p5.x)) * (min(p4.y, p6.y) - max(p3.y, p5.y));

  if (areaI < 0)
  {
    // they do not intersect
    cout << "YES" << endl;
    exit(0);
  }
  if ((area1 + area2 - areaI) == area)
  {
    cout << "NO" << endl;
  }
  else
    cout << "YES" << endl;
  return 0;
}
