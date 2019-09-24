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
#define mem(x,y) memset(x,y,sizeof(x))

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  //cin>>t;
  while(t--){
      int n;
      cin>>n;
      string str;
      cin>>str;
      int count[26];
      mem(count,0);
      for(int i=0;i<n;i++)
      {
          count[str[i]-'a']++;
      }
      // f(i,0,26)
      // cout<<count[i]<<" ";
      int one = 0;
      one = min(count[14],min(count[13],count[4]));
      int zero = min(count[14]-one,min(count[25],min(count[17],count[4]-one)));
      // cout<<zero<<" "<<one<<endl;
      for(int i=0;i<one;i++)
      {
          cout<<1<<" ";
      }
      for(int i=0;i<zero;i++)
      {
          cout<<0<<" ";
      }
  }
  return 0;
}
