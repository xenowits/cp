//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i < b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e6+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll t=1;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++)
        cin>>arr[i];
        ll peak[n];
        memset(peak,0,sizeof(peak));
        for(ll i=1;i<n-1;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                peak[i]=1;
        }
        for(ll i=1;i<n;i++)
        peak[i]+=peak[i-1];
        ll ans=0,maxi=INT_MIN;
        for(ll i=k-1;i<n;i++)
        {
            if(i==k-1)
            {
                ll x=peak[i-1];
                if(maxi<x)
                {
                    maxi=x;
                    ans=i-k+1;
                }
            }
            else
            {
                ll x=peak[i-1]-peak[i-k+1];
                if(maxi<x)
                {
                    maxi=x;
                    ans=i-k+1;
                }
            }
        }
        cout<<peak[ans+k-2]-peak[ans]+1<<" "<<ans+1<<endl;
    }
	return 0;
}
