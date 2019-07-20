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

vector<ll> h1(100005), h2(100005);
vector<ll> dp1(100005), dp2(100005);

ll n;

void solve()
{
  ll max1, max2;
  fori(i,1,n)
  {
    if (i == 1)
    {
      dp1[i] = h1[i];
      dp2[i] = h2[i];
      max1 = h1[i];max2 = h2[i];
    }
    else
    {
      dp1[i] = h1[i] + max2;
      dp2[i] = h2[i] + max1;
      max1 = max(dp1[i],max1);
      max2 = max(dp2[i],max2);
    }
  }
  cout << max(max1,max2) << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  fori(i,1,n)
    cin >> h1[i];
  fori(j,1,n)
    cin >> h2[j];

  solve();

  return 0;
}
