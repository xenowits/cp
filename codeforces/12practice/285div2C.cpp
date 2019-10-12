#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> a(n+1);
  fori(i,1,n)
    cin >> a[i];
  sort(a.begin()+1,a.end());
  ll cost = 0;
  fori(i,1,n)
  {
    cost += abs(a[i]-i);
    //cout << a[i] << " " << i << " " << abs(a[i]-i) << endl;
  }
  cout << cost;
  return 0;
}
