#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

void print(vector<ll> v)
{
  fori(i,1,v.size()-1)
    cout << v[i] << " ";
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t,n;
  cin >> t;
  while (t>0)
  {
    cin >> n;
    vector<ll> v(n+1),diff(n+1);
    unordered_map<ll,ll> umap;
    set<int> s;ll d,X;
    fori(i,1,n)
    {
      cin >> v[i];
      if (i>1)
      {
        diff[i] = v[i]-v[i-1];
        s.insert(diff[i]);
        umap[diff[i]] += 1;
      }
    }
    if (n == 4)
    {
      if (s.size() == 3)
      {
        //cout << "ghus gya m to" << endl;
        ll sum = 0;
        for (auto x : s)
        {
          sum += x;
        }
        d = sum/3;
      }
      else if (s.size() == 2)
      {
        ll a = diff[2];
        ll b = diff[3];
        ll c = diff[4];
        //cout << a << " " << b << " " << c << endl;
        if (a == b)
          d = a;
        if (b == c)
          d = b;
        else if (a == c)
          d = a;
      }
    }
    if (n > 4)
    {
      ll minmax = INT_MIN;
      for(auto x : s)
      {
        if (umap[x] > minmax)
        {
          minmax = umap[x];
          d = x;
        }
      }
    }
    //cout << "d here is " << d << endl;
    s.erase(d);
    vector<ll> ans;
    ans = v;
    if (s.size() == 0)
    {
      // cout << "yeha h" << endl;
      print(ans);
    }
    if (s.size() == 1)
    {
      if (diff[2] != diff[3])
      {
        ans[1] = v[2] - d;
        print(ans);
      }
      else
      {
        ans[n] = v[n-1] + d;
        print(ans);
      }
    }
    else if (s.size() > 1)
    {
      //cout << "else wala block d is " << d << endl;
      ll someThing;
      fori(i,1,n)
      {
        if (i >= 2)
        {
            cout << someThing+d << " ";
            someThing = someThing+d;
        }
        else
        {
          cout << v[i] << " ";
          someThing = v[i];
        }
      }
      cout << endl;
    }
    t-=1;
  }
  return 0;
}
