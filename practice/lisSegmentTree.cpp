#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int n, i, ans[1000005], out;
int T[1000005];

int query(int v, int tl, int tr, int l, int r)
{
  if (l>r)
    return 0;
  if (tl == l && tr == r)
    return T[v];
  int tm = (tl+tr)/2;
  return max(query(2*v,tl,tm,l,min(tm,r)),query(2*v+1,tm+1,tr,max(tm+1,l),r));
}

void update(int v, int tl, int tr, int pos, int val)
{
  if (tl == tr)
  {
    T[v] = val;
    return;
  }
  int tm = (tl+tr)/2;
  if (tm >= pos)
    update(2*v,tl,tm,pos,val);
  else
    update(2*v+1,tm+1,tr,pos,val);
  T[v] = max(T[2*v],T[2*v+1]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n+1);
  fori(i,1,n)
    cin >> a[i];
  fori(i,1,n)
  {
    ans[a[i]] = query(1,1,n,1,a[i]-1)+1;
    update(1,1,n,a[i],ans[a[i]]);
    out = max(out,ans[a[i]]);
  }
  cout << out << endl;
  return 0;
}
