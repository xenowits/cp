#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i < b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define lli long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin>>t;
  while(t--)
  {
    lli n,m;
    cin>>n>>m;
    lli q = n/m;
    lli ans[10];
    for(int i=0;i<10;i++)
    {
        ans[i]=(m*i)%10;
    }
    int total = 0;
    fori(i,0,10)
      total+=ans[i];
    if(q==0)
      cout<<0<<endl;
    else
    {
        int remainder = q%10;
        lli done = q/10;
        done = done * total ;
        fori(i,1,remainder+1)
          done += ans[i];
        cout<<done<<endl;
    }
  }
  return 0;
}
