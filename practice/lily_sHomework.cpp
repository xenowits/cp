#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,temp;
  cin >> n;
  vector<bool<ll,ll> > arr(n+1);
  vector<ll> permutation(n+1);
  fori(i,1,n)
  {
      cin >> temp;
      arr.pb(mk(temp,i));
  }
  sort(arr.begin()+1,arr.end());
  fori(i,1,n)
  {
    permutation[arr[i].second] = i;
  }
  fori(i,1,n)
    cout << permutation[i] << " ";
  cout << endl;
  return 0;
}
