#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k;
  cin>>n>>k;
  ll arr[n+1];
  fori(i,1,n)
  cin>>arr[i];
  ll pre[n+1];
  pre[1]=arr[1];
  fori(i,2,n)
  pre[i]=pre[i-1]+arr[i];
  ll start[n+1],end[n+1];
  fori(i,1,n-k+1)
  {
    if(i!=1)
    start[i]=pre[i+k-1]-pre[i-1];
    else
    start[i]=pre[i+k-1];
  }
  // fori(i,1,n-k+1)
  // cout<<start[i]<<" ";
  ford(i,n,k)
  {
    if(i>k)
    end[i]=pre[i]-pre[i-k];
    else
    end[i]=pre[i];
  }
  // cout<<endl;
  // fori(i,k,n)
  // cout<<end[i]<<" ";
  pair<ll,ll>ans;
  ll track_max=start[n-k+1],max_sum=INT_MIN,a,b=n-k+1,sum;
  ford(i,n-k,k)
  {
    if(track_max<=start[i+1])
    {
      track_max=start[i+1];
      b=i+1;
    }
    sum=end[i]+track_max;
    if(max_sum<=sum)
    {
      max_sum=sum;
      a=i-k+1;
      if (a < b)
        ans=mk(a,b);
    }
  }
  cout<<ans.first<<" "<<ans.second;
  return 0;
}
