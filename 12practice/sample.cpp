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
#define pi pair<int,int>
#define s second
#define f first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,temp;
  cin >> n;

  vector<int> v;
  fori(i,1,n)
  {
    cin >> temp;
    v.pb(temp);
  }

  sort(v.begin(), v.end());

  

  return 0;
}
