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

  int n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  vector<int> ab, ba;

  fori(i,0,n-1)
  {
    if (a[i] == 'a' && b[i] == 'b')
      ab.pb(i);
    else if (a[i] == 'b' && b[i] == 'a')
      ba.pb(i);
  }
  //dono even ho ya dono odd ho
  if ((ab.size() + ba.size())%2 == 1)
  {
    cout << -1 << endl;
    exit(0);
  }

  ll na = ab.size(), nb = ba.size();

  if (na%2 == 0 && nb%2 == 0)
  {
    cout << na/2+nb/2 << endl;
    for(int i = 0; i < ab.size(); i += 2)
    {
      cout << ab[i]+1 << " " << ab[i+1]+1 << endl;
    }

    for(int i = 0; i < ba.size(); i += 2)
    {
      cout << ba[i]+1 << " " << ba[i+1]+1 << endl;
    }
  }

  else
  {
    cout << na/2+nb/2+2 << endl;
    for(int i = 0; i < ab.size()-1; i += 2)
    {
      cout << ab[i]+1 << " " << ab[i+1]+1 << endl;
    }

    for(int i = 0; i < ba.size()-1; i += 2)
    {
      cout << ba[i]+1 << " " << ba[i+1]+1 << endl;
    }
    cout << ba[nb-1]+1 << " " << ba[nb-1]+1 << endl;
    cout << ab[na-1]+1 << " " << ba[nb-1]+1 << endl;
  }

  return 0;
}
