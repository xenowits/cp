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
#define pi pair<int,int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t)
  {
    ll n,k;
    cin >> n >> k;
    if (k%3 == 0)
    {
      ll r = n%(k+1);
      if (r%3 != 0 || r == k)
      {
        cout << "Alice" << endl;
      }
      else
        cout << "Bob" << endl;
    }
    else
    {
      if (n%3 == 0)
        cout << "Bob" << endl;
      else
        cout << "Alice" << endl;
    }
    t-=1;
  }
  return 0;
}
