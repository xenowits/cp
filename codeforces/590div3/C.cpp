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


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;

  while (q--)
  {
    ll n;
    cin >> n;

    vector<int> a(n), b(n);
    cout << n << endl;
    fori(i,0,n-1)
    {
      cin >> a[i];
      if (a[i] == 1 || a[i] == 2)
        a[i] = 1;
      else
        a[i] = 3;
    }
    fori(i,0,n-1)
    {
      cin >> b[i];
      if (b[i] == 1 || b[i] == 2)
        b[i] = 1;
      else
        b[i] = 3;
    }
    bool truth = 0;
    ll cnt = 0;
    if (b[n-1] == 3)
    {
      fori(i,1,n-1)
      {
        if (a[i] == 1 && b[i] == 1)
          cnt += 1;
        else if (a[i] != b[i])
        {
          truth = 1;
          break;
        }
      }
    }
    else if (b[n-1] == 1)
    {
      fori(i,1,n-2)
      {
        if (a[i] == 1 && b[i] == 1)
          cnt += 1;
        else if (a[i] != b[i])
        {
          truth = 1;
          break;
        }
      }
    }
    if (truth)
    {
      cout << "NO" << endl;
    }
    cout << q << endl;
  }

  return 0;
}
