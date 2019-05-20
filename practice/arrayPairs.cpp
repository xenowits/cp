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

long getMax(long v, long tl, long tr, long l, long r)
{
  //cout << tl << " " << tr << " " << l << " " << r << endl;
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v];
  long tm = (tl+tr)/2;
  return max( getMax(2*v, tl, tm, l, min(r,tm)) , getMax(2*v+1, tm+1, tr, max(l, tm+1), r) );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    // cout << "hello friends chai pilo" << endl;
    cin >> n;
    vector<ll> a(n);
    fori(i,0,n-1)
      cin >> a[i];
    buildMax(a,1,0,n-1);
    ll count = 0;
    for (int i = 0 ; i < n; ++i)
    {
      for(int j = i+1; j < n; ++j)
      {
        ll temp1 = a[i]*a[j];
        ll temp2 = getMax(1,0,n-1,i,j);
        //cout << i << " " << j << " " << temp1 << " " << temp2 << endl;
        if (temp1 <= temp2)
        {
            count += 1;
            //cout << "Britannia " << i << " " << j << endl;
        }
      }
    }
    //cout << "hello friends chai pilo 2" << endl;
    std::cout << count << endl;
    // for (int i = 1; i <= 4*n ; ++i)
    // {
    //   cout << i << " " << t[i] << endl;
    // }
    return 0;
}
