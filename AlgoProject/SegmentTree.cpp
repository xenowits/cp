#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

ll t[4*MAXN];

void build(vector<ll> a, long v, long tl, long tr)
{
  if (tl == tr)
    t[v] = a[tl];
  else
  {
    long tm = (tl+tr)/2;
    build(a, 2*v, tl, tm);
    build(a, 2*v+1, tm+1, tr);
    t[v] = t[2*v] + t[2*v+1];
  }
}

void buildMax(vector<ll> a, long v, long tl, long tr)
{
  if (tl == tr)
    t[v] = a[tl];
  else
  {
    long tm = (tl+tr)/2;
    buildMax(a, 2*v, tl, tm);
    buildMax(a, 2*v+1, tm+1, tr);
    t[v] = std::max(t[2*v], t[2*v+1]);
  }
}

long sum(long v, long tl, long tr, long l, long r)
{
  cout << tl << " " << tr << " " << l << " " << r << endl;
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v];
  long tm = (tl+tr)/2;
  return sum(2*v, tl, tm, l, min(r,tm)) + sum(2*v+1, tm+1, tr, max(l, tm+1), r);
}

void update(long v, long tl, long tr, long pos, long new_val)
{
  if (tl == tr)
    t[v] = new_val;
  else
  {
    long tm = (tl+tr)/2;
    if (pos <= tm)
      update(2*v, tl, tm, pos, new_val);
    else
      update(2*v+1, tm+1, tr, pos, new_val);
    t[v] = t[v*2] + t[v*2+1];
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<ll> a(n);
    cin >> n;
    fori(i,0,n-1)
      cin >> a[i];
    build(a,1,0,n-1);
    for (int i = 1; i <= 4*n ; ++i)
    {
      cout << t[i] << " ";
    }
    cout << endl;
    cout << sum(1,0,n-1,1,4);
    cout << endl;
    update(1,0,n-1,2,1);
    cout << sum(1,0,n-1,1,4);
    return 0;
}
