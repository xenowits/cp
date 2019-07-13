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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> v(n);
  fori(i,0,n-1)
    cin >> v[i];
  stack<ll> stk;
  vector<ll> ans(n,-1);
  fori(i,0,n-1)
  {
    if (!stk.empty() && v[i] > v[stk.top()])
    {
      int temp;
      while(!stk.empty() && v[stk.top()] < v[i])
      {
        temp = stk.top();
        stk.pop();
        ans[temp] = i;
      }
    }
    stk.push(i);
  }
  cout << "The next greater elements are as follows:" << endl;
  fori(i,0,n-1)
  {
    if (ans[i] == -1)
      cout << -1 << endl;
    else
      cout << i << " " << v[ans[i]] << endl;
  }
  return 0;
}
