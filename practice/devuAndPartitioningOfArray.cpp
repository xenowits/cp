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

vector<int> vo(100001);
vector<pi> ve;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k,p;
  cin >> n >> k >> p;
  ll temp;
  vector<ll> odd,even;
  fori(i,1,n)
  {
    cin >> temp;
    if (temp&1)
      odd.pb(temp);
    else
      even.pb(temp);
  }
  int no = odd.size(), ne = even.size();
  if (no < k-p || (no-k+p)&1 || (ne+(no-k+p)/2 < p))
  {
    cout << "NO" << endl;
    exit(0);
  }
  //fill the odd k-p parts from the odd vector
  cout << "YES" << endl;
  int i = 0;
  for(i = 0; i < k-p; ++i)
  {
    //vo[i+1] = odd[i];
    cout << 1 << " " << odd[i] << endl;
  }

  // fill the even p parts from the odd pairs
  int s = 0;
  for(i = k-p; i < no && s < p ; i += 2)
  {
    ve.pb(mk(odd[i], odd[i+1]));
    s += 1;
  }
  cout << ve.size() << " h size" << endl;
  // odd exhausted by now
  i = 0;

  if (ve.size() > 0 && ve.size() < p)
  {
    //cout << "m yeha hoo" << endl;
    int j;
    int nn = ve.size();

    for(auto x : ve)
    {
      cout << 2 << " " << x.fs << " " << x.sc << endl;
    }
    //cout << nn << " nn h" << endl;
    int rem = p-nn;
    for(j = 0; j < rem-1; ++j)
    {
      cout << 1 << " " << even[j] << endl;
    }
    cout << (even.size()-j);
    for(;j < ne; ++j)
      cout << " " << even[j];
    cout << endl;
  }
  else if (ve.size() == p)
  {
    cout << "kaha" << endl;
    cout << ne+2 << " " << ve[0].fs << " " << ve[0].sc;
    for(int x : even)
      cout << " " << x;
    cout << endl;
    for(int j = 1; j < p; ++j)
    {
      cout << 2 << " " << ve[j].fs << " " << ve[j].sc << endl;
    }
  }
  else if (ve.size() == 0)
  {
    int i;
    for(i = 0; i < p-1;++i)
      cout << 1 << " " << even[i] << endl;
    cout << ne-p+1;
    for(;i<ne;++i)
      cout << " " << even[i];
  }
  return 0;
}
