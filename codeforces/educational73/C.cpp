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

bool compu(int a,int b)
{
    if(a!=b)
    return a>b;
    else
    return a>b;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q = 1;
  cin>>q;
  while(q--)
  {
    ll n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n,compu);
    bool flag = false;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>2048)
        {
            continue;
        }
        else
        {
            sum+=arr[i];
        }
        if(sum == 2048)
        {
            flag = true;
        }
    }
    if(flag )
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
  return 0;
}
