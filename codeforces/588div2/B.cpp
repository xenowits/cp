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

    ll n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        char a;
        cin>>a;
        arr[i]=a-'0';
    }
    if(n == 1 and k>0)
    {
        cout<<0<<endl;
        return 0;
    }
    ll count =0;
    for(int i=0;i<n;i++)
    {
        if(count<k)
        {
            if(i==0)
            {
                if(arr[i]!=1)
                {
                    arr[i] = 1;
                    count++;
                }
            }
            else
            {
                if(arr[i]!=0)
                {
                    arr[i] = 0;
                    count++;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

  return 0;
}
