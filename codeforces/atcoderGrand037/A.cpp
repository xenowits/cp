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

  ll n,k;
  cin >> n >> k;

  ll ans = 0;
  //vector<bool> v(32,0);
  queue<ll> q;
  int cnt = 0;
  ford(i,31,0)
  {
    ll temp = (ll)pow(2,i);
    if (temp + ans <= n)
      ans += temp, cnt += 1, q.push(temp);
  }
  if (cnt > k || n < k)
    cout << "NO" << endl;
  else
  {
    while (q.size() != k)
    {
      ll t = q.front();
      q.pop();
      //cout << t << endl;
      if (t > 1)
      {
        q.push(t/2);
        q.push(t/2);
      }
      else
        q.push(t);
    }
    cout << "YES" << endl;
    while (!q.empty())
    {
      cout << q.front() << " ";
      q.pop();
    }
  }

  return 0;
}
