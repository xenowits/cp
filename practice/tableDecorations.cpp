#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>

int main()
{
  ll a,b,c;
  vector<ll> v;
  cin >> a >> b >> c;
  ll softmax = max(max(a,b),c);
  ll softmin = min(min(a,b),c);

  priority_queue<int> q;
  q.push(a);q.push(b);q.push(c);

  ll ans = 0;

  while (softmax - softmin > 1)
  {
    a = q.top();
    a -= 2;
    q.pop();
    b = q.top();
    b-=1;
    q.pop();
    c = q.top();
    q.pop();
    softmax = max(max(a,b),c);
    softmin = min(min(a,b),c);
    q.push(a);q.push(b);q.push(c);
    ans += 1;
  }

  ll temp = q.top();q.pop();
  temp += q.top();q.pop();
  temp += q.top();q.pop();

  ans += (temp)/3;

  cout << ans << endl;

  return 0;
}
