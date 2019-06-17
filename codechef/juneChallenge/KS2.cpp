#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

ll sumOfdgs(ll i)
{
  ll sum = 0;
  while (i)
  {
    ll temp = i%10;
    sum += temp;
    i = i/10;
  }
  return sum;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // ll cnt = 0;
  // fori(i,10000,1000000)
  // {
  //   int temp = sumOfdgs(i);
  //   if (temp%10 == 0)
  //   {
  //     cnt += 1;
  //     cout << cnt+999 << " " << temp << " " << i << endl;
  //   }
  // }
  // cout << cnt << endl;
  ll t;
  cin >> t;
  while(t>0)
  {
    ll n;
    cin >> n;
    ll temp = sumOfdgs(n);
    int i,so;
    for(int i = 0; i <= 9;++i)
    {
      if ((temp+i)%10 == 0)
      {
        so = i;
        break;
      }
    }
    cout << n << so << endl;
    t-=1;
  }
  return 0;
}
