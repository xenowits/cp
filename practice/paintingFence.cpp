#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<int> a(5005);
ll ans = 0,n;
int t[4*5005], indx[4*5005];

void build(int v, int tl, int tr)
{
    if (tl == tr) {
        t[v] = a[tl];
        indx[v] = tl;
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[v*2],t[v*2+1]);
        if (t[v*2] <= t[v*2+1])
        {
          t[v] = t[v*2];
          indx[v] = indx[v*2];
        }
        else
        {
          t[v] = t[v*2+1];
          indx[v] = indx[v*2+1];
        }
    }
}

int rmq(int v, int tl, int tr, int l, int r)
{
    cout << v << " " << l << " " << r << endl;
    if (l > r)
        return -1;
    if (l == tl && r == tr) {
        return indx[v];
    }
    int tm = (tl + tr) / 2;
    //cout << l << " " << tm << " " << r << endl;
    int x = rmq(v*2, tl, tm, l, min(r, tm));
    int y = rmq(v*2+1, tm+1, tr, max(l, tm+1), r);
    if (x == -1 || y == -1)
      return max(x,y);
    if (a[x] <= a[y])
      return x;
    else
      return y;
}

int solve(int h,int l, int r)
{
  if (l > r)
    return 0;
  int aindx = rmq(1,0,n-1,l,r), m = a[aindx];
  // int m = INT_MAX,aindx;
  // fori(i,l,r)
  // {
  //   if (a[i] < m)
  //   {
  //     m = a[i];
  //     aindx = i;
  //   }
  // }

  int a = solve(m,l,aindx-1);
  int b = solve(m,aindx+1,r);
  return min(r-l+1,a+b+m-h);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  fori(i,0,n-1)
    cin >> a[i];
  //build(1,0,n-1);

  //cout << solve(0,0,n-1);
  // cout << ans << endl;
  cout << rmq(1,0,n-1,2,3);
  return 0;
}
