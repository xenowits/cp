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
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,temp;
  cin >> n;

  vector<int> even , odd;
  ll eadd = 0, oadd = 0;
  fori(i,1,n)
  {
    cin >> temp;
    if (temp%2 == 0)
      even.pb(temp), eadd += temp;
    else
      odd.pb(temp), oadd += temp;
  }

  sort(even.begin(), even.end(), greater<int>());
  sort(odd.begin(),odd.end(), greater<int>());

  int n1 = even.size() , n2 = odd.size();
  if (n1 == 0)
  {
    cout << eadd+oadd - odd[0] << endl;
    exit(0);
  }
  if (n2 == 0)
  {
    cout << oadd+eadd - even[0] << endl;
    exit(0);
  }
  if (abs(n1-n2) < 2)
  {
    cout << 0 << endl;
  }
  else if (n1 < n2)
  {
    ll sum = 0;
    for(int i = 0; i < n1; ++i)
      sum += odd[i], sum += even[i];
    cout << eadd + oadd - (sum+odd[n1]);
  }
  else
  {
    ll sum = 0;
    for(int i = 0; i < n2; ++i)
      sum += even[i], sum += odd[i];
    cout << eadd+oadd - (sum+even[n2]);
  }
  return 0;
}
