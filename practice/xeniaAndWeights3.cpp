#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define test()    int test_case;cin>>test_case;while(test_case--)
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define si(a) scanf("%i",&a)
#define sd(a)  scanf("%ld",&a)
#define sf(a) scanf("%f",&a)
#define rn(a) return a
#define pai pair<int,int>
#define pal pair<li,li>
#define pall pair<lli,lli>
#define ff first
#define ss second
#define mod  1000000007
#define mp make_pair
#define pb push_back
#define pll(a) printf("%lld\n",a)
#define pl(a) printf("%lld\n",a)
#define pi(a) printf("%d\n",a)
#define pd(a) printf("%lf\n",a)
#define pf(a) printf("%f\n",a)
#define lc (start+end)/2
#define rc  lc+1
char arr[12];
int dp[12][10001][12];// diff ,length made  , last used

int build(int last,int diff,int length,int ans[],int pos)
{
    if(dp[diff][length][last] !=0) return 1;

    else if(length==0)
    {
      cout<<"YES"<<endl;
      for(int i=0;i<pos;i++) cout<<ans[i]<<" ";
      exit(0);
    }
    else
     {
      dp[diff][length][last]=1;
      for(int i=0;i<=10;i++)
       {
          if(arr[i]=='1' && i+1!=last && i+1>diff)
          {
           ans[pos]=i+1;
           build(i+1,i+1-diff,length-1,ans,pos+1);
           }
       }
  }
  return 0;
}

int ans[10000];
int main()
 {
   cin>>arr;
   int m;
    cin>>m;
    int s=build(0,0,m,ans,0);
    cout<<"NO"<<endl;
 }
