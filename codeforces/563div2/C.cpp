#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define MAXN 100001

vector<int> ans(MAXN,0);
int z = 1;

void sieve(int n)
{
    for(int i = 2; i <= n; ++i)
    {
      bool change = false;
      for(int j = i ; j <= n; j+=i)
      {
        if (ans[j] == 0)
        {
          ans[j] = z;
          change = true;
        }
      }
      if (change)
        z+=1;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  // vector<int> a(n+1);
  // fori(i,2,n)
  //   cin >> a[i];
  sieve(n);
  fori(i,2,n)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
