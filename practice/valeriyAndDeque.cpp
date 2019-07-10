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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;ll temp,q;
  cin >> n >> q;
  deque<int> dq;
  fori(i,1,n)
  {
    cin >> temp;
    dq.push_back(temp);
  }
  ll diff = dq.front() - *(dq.begin()+1);
  //cout << diff << " diff h" << dq.front() << " " << *(dq.begin()+1) << endl;
  vector<pi> vpi(n+1);
  ll x = 0;
  while(diff<0)
  {
    ll a = dq.front();
    dq.pop_front();
    dq.push_back(a);
    diff = dq.front() - *(dq.begin()+1);
    x += 1;
    vpi[x] = (mk(dq.front(),a));
  }
  cout << x << " x h bhaiaya " << endl;
  for (auto a : dq)
    cout << a << " ";
  cout << endl;
  ll N = n-1;
  ll maxu = dq.front();
  dq.pop_front();
  vector<int> v;
  for(auto a : dq)
  {
    temp = dq.front();
    dq.pop_front();
    v.pb(temp);
  }
  cout << "answer follows" << endl << endl << endl;
  while (q>0)
  {
    ll m;
    cin >> m;
    if (m <= x)
    {
      cout << vpi[m].second << " "<< vpi[m].first << endl;
    }
    else
    {
      //cout << (m-x)%N << " ji " << endl;
      cout << maxu << " " << v[(m-x-1)%(n-1)] << endl;
    }
    q-=1;
  }
  return 0;
}
