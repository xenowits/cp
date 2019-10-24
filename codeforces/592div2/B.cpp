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

  int t;
  cin >> t;
  while (t--)
  {
    ll n;
     cin>>n;
     string str;
     cin>>str;
     ll start = n;
     ll end = 0;
     for(ll i=0;i<n;i++)
     {
         if(str[i]=='1')
         {
             start = min(start,i);
             end = max(end,i+1);
         }
     }
     ll ans = max(n-start,end);
     ans = 2*ans;
     ans = max(ans,n);
     if(ans==0)
     {
         cout<<n<<endl;
     }
     else
     {
         cout<<ans<<endl;
     }
  }
  return 0;
}
