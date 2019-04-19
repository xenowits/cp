#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

void solve(vector<ll> v, ll l, ll r, int n)
{
  if (n == 1)
  {
    cout << r-l+1;
    return;
  }
  if (l != r)
  {
    vector<pair<ll,ll> > segments;
    fori(i,1,n)
    {
      segments.pb(mk(v[i]+l,v[i]+r));
    }
    sort(segments.begin(), segments.end());
    // for (auto x : segments)
    //   cout << " " << x.first << " " << x.second << endl;
    ll total = 0, p, q,a,b,c,d;
    p = segments[0].first;
    q = segments[0].second;
    fori(i,0,n-2)
    {
      a = segments[i].first;
      b = segments[i].second;
      c = segments[i+1].first;
      d = segments[i+1].second;
      if (c >= a && c <= b)
      {
        //i = a;
        q = d;
        //cout << p << " p aur d " << q << endl;
      }
      else
      {
        //cout << p << " p aur d " << q << endl;
        total += q-p+1;
        //cout << total << " dekho bhai\n";
        p = c;
        q = d;
      }
    }
    cout << total+q-p+1;
  }
  if (l == r)
  {
    set<ll> nos;
    fori(i,1,n)
      nos.insert(v[i]+l);
    cout << nos.size();
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q;
  long long l,r;
  cin >> n;
  vector<long long> v(n+1);
  fori(i,1,n)
  {
    cin >> v[i];
  }
  cin >> q;
  while (q>0)
  {
    cin >> l >> r;
    //cout << l << " " << r << " are here\n";
    solve(v,l,r,n);
    q-=1;
    if (q>0)
      cout << " ";
  }
  return 0;
}
// 1
// 34670175354172502
// 5
// 136994356890846099 828005319262620596
// 518016312602443432 944640731306210984
// 143546617512856816 819547311437046215
// 1968403510995697 961085202646072506
// 390992055497658258 506085339866980699
