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

int arr[1005][1005];
int rtt[10005];
int ltt[10005];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

    int a,b;
   cin>>a>>b;
   memset(arr,0,sizeof(arr));
   for(int i=0;i<a;i++)
   {
       cin>>ltt[i];
   }
   for(int i=0;i<b;i++)
   {
       cin>>rtt[i];
   }
   for(int i=0;i<a;i++)
   {
       int j = 0;
       for(;j<ltt[i];j++)
       {
           arr[i][j] = 1;
       }
       arr[i][j]= -1;
   }

   for(int i=0;i<b;i++)
   {
       int j=0;
       for(;j<rtt[i];j++)
       {
           if(arr[j][i]==-1)
           {
               cout<<0<<endl;
               return 0;
           }
           else
           {
               arr[j][i] = 1;
           }

           // arr[j][i] = true;
       }
       arr[j][i] = -1;
   }
   ll ans  = 1;
   for(int i=0;i<a;i++)
   {
       for(int j=0;j<b;j++)
       {
           // cout<<arr[i][j]<<" ";
           if(arr[i][j]==0)
           {
               ans=ans*2;
               ans%=mod;
           }
       }
       // cout<<endl;
   }
   cout<<ans<<endl;
  return 0;
}
