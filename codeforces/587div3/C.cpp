#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i < b ; ++i)
#define ford(i,a,b) for(long int i = a;i > b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (ll i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

    ll n;
    cin>>n;

    ll a[n];

    fori(i,0,n)
    cin>>a[i];

    ll maxi=INT_MIN;
    fori(i,0,n)

    maxi=max(maxi,a[i]);

    ll cnt=0;
    fori(i,0,n)
    cnt+=(abs(maxi-a[i]));

    if(isPrime(cnt))
    {
        cout<<1<<" "<<cnt;
        return 0;
    }
    ll res2=INT_MAX;
    fori(i,0,n)
    res2=min(res2,maxi-a[i]);
    fori(i,0,n)
    res2=__gcd(res2,(maxi-a[i]));
    cout<<(cnt/res2)<<" "<<res2;
}
