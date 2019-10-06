#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i < b ; ++i)
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

  int t = 1;
//cin>>t;
while(t--){
  ll n,k;
  cin>>n>>k;
  ll arr[n];
  fori(i,0,n) cin>>arr[i];
  deque<ll>q;
  ll curr = 0;
  map<ll,bool> hello;
  while(q.size()!=k and curr<n)
  {
    if(hello[arr[curr]]==false)
    {
      q.push_front(arr[curr]);
      hello[arr[curr]] = true;
    }
    curr++;
  }


  while(curr<n)
  {
    if(hello[arr[curr]]==false)
    {
      ll temp = q.back();
      hello[temp] = false;
      q.pop_back();
      q.push_front(arr[curr]);
      hello[arr[curr]] = true;
    }
    curr++;

  }
  cout<<q.size()<<endl;
  for(auto&i:q)
  {
    cout<<i<<" ";
  }

}

  return 0;
}
