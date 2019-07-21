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
#define fs first
#define sc second

void spanStock(vector<int> v, int n)
{
  stack<int> stk;
  stk.push(0);
  vector<int> ans(n);
  ans[0] = 1;
  fori(i,1,n-1)
  {

    while (!stk.empty() && v[stk.top()] <= v[i])
      stk.pop();

    ans[i] = (stk.empty() ) ? (i+1) : (i-stk.top());

    stk.push(i);
  }

  fori(i,0,n-1)
    cout << ans[i] << " ";
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  vector<int> v(n);
  fori(i,0,n-1)
    cin >> v[i];

  spanStock(v,n);

  return 0;
}
