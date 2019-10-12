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

struct Point{
  int x, y;
  Point(int p, int q):x(p), y(q){}
};

int n;
int arr[51][51];
vector<Point> fuck1, fuck2;

vector<int> xdisplace = {-1,1,0,0};
vector<int> ydisplace = {0,0,-1,1};

ll dist(Point a, Point b)
{
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

void dfs(Point a, vector<Point> &fuck)
{
  arr[a.x][a.y] = 1;
  fuck.pb(a);

  for(int i = 0; i < 4; ++i)
  {
    Point temp = {a.x+xdisplace[i], a.y+ydisplace[i]};
    if (temp.x >= 1 && temp.x <= n && temp.y >= 1 && temp.y <= n && arr[temp.x][temp.y] == 0)
      dfs(temp,fuck);
  }
}

ll solve()
{
  ll ans = INT_MAX;

  for (auto x : fuck1)
  {
    for (auto y : fuck2)
    {
      ans = min(ans,dist(x,y));
    }
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r1, c1, r2, c2;
  cin >> n;
  cin >> r1 >> c1 >> r2 >> c2;

  Point x = {r1, c1}, y = {r2, c2};

  fori(i,1,n){
    string s;
    cin >> s;
    fori(j,1,n){
      arr[i][j] = s[j-1]-'0';
    }
  }

  //component containing P1 AND P2

  dfs(x,fuck1);
  dfs(y,fuck2);

  //shortest distance between these components

  cout << solve() << endl;

  return 0;
}
