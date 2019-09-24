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

int t[4*5005], indx[4*5005];
vector<int> a(5005);

void build(int v, int tl, int tr) {
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

int rmq(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return indx[v];
    }
    int tm = (tl + tr) / 2;
    int x = rmq(v*2, tl, tm, l, min(r, tm));
    int y = rmq(v*2+1, tm+1, tr, max(l, tm+1), r);
    if (a[x] <= a[y])
      return x;
    else
      return y;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fori(i,0,4)
    cin >> a[i];
  build(1,0,4);
  cout<<rmq(1,0,4,1,3);
  return 0;
}
