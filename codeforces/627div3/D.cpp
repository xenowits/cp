//xenowitz -- Jai Shree Ram
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

ll dp[2005][2005];

int solve(ll* arr,int n,int h,int l,int r,int i,int total) {
    if(i == n) {
        return 0;
    }
    if(dp[i][total]!=-1){
        return dp[i][total];
    }
    else {
        int time1 = total+arr[i];
        int time2 = total+arr[i]-1;
        time1 %= h;
        time2 %= h;
        int flag1 = 0;
        bool flag2 = 0;
        if(time1>=l and time1<=r){
            flag1 = 1;
        }
        if(time2>=l and time2<=r){
            flag2 = 1;
        }
        dp[i][total] = max(flag1 + solve(arr,n,h,l,r,i+1,time1),flag2+solve(arr,n,h,l,r,i+1,time2));
        return dp[i][total];
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  //cin >> t;
  t = 1;
  while(t--){
      int n, h, l, r;
      cin >> n >> h >> l >> r;
      ll arr[n];
      for(int i = 0; i < n; i++){
          cin >> arr[i];
      }

      mem(dp,-1);
      int ans = solve(arr,n,h,l,r,0,0);
      cout<<ans<<endl;
  }
  return 0;
}
