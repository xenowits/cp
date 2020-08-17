//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i < b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define eb emplace_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define stf shrink_to_fit

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t=1;
cin>>t;
while(t--)
{
  ll n;
  cin>>n;
  ll x=(n/2);
  if(x%2)
    cout<<"NO"<<endl;
  else
  {
    vector<ll>v;
    ll sum=0,s=0;
    fori(i,0,x)
    {
      sum+=((i+1)*2);
      v.pb((i+1)*2);
    }
    fori(i,0,x-1)
    {
      s+=((2*i)+1);
      v.pb((2*i+1));
    }
    v.pb(sum-s);
    cout<<"YES"<<endl;
    for(auto i:v)
      cout<<i<<" ";
    cout<<endl;
  }
}

	return 0;
}
