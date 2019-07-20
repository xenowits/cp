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
#define MAXN 998244353

ll n,k;
vector<ll> a(100007), kvc(50,0);

void countK()
{
  ll tp = a[1], digits = 0;
  while (tp)
  {
    tp = tp/10;
    digits+=1;
  }
  k = digits;
}

vector<ll> give(ll num)
{
  vector<ll> v;
  stack<ll> s;

  while (num)
  {
    s.push(num%10);
    num = num/10;
  }

  while(!s.empty())
  {
    v.pb(s.top());
    s.pop();
  }
  // for(int p : v)
  //   cout << p << " ";
  // cout << endl;
  return v;
}

void solve()
{
  fori(i,1,n)
  {
    vector<ll> temp = give(a[i]);
    ll j =1;
    for(int x : temp)
    {
      kvc[j] += n*x;
      kvc[j+1] += n*x;
      j += 2;
    }
    // fori(i,1,2*k)
    //   cout << kvc[i] << " ";
    // cout << endl;
  }

  ll plc = 1, ans = 0, carry = 0;

  ford(i,2*k,1)
  {
    ll tp = kvc[i] + carry;
    ans = ( ans + ((plc*(tp%10) )%MAXN) )%MAXN;
    carry = tp/10;
    plc = (plc%MAXN)*10;
    //cout << ans << " ans and kvc " << kvc[i] << endl;
  }

  while (carry)
  {
    ans = (ans + (plc%MAXN)*(carry%10))%MAXN;
    carry /= 10;
    plc *= 10;
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  fori(i,1,n)
    cin >> a[i];

  countK();

  solve();

  return 0;
}
