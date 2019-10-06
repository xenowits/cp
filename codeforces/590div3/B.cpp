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
#define pi pair<long long int,long long int>
#define sc second
#define fs first

void print(deque<ll> dq)
{
  while (!dq.empty())
  {
    cout << dq.front() << " ";
    dq.pop_front();
  }
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k;
  cin >> n >> k;
  set<ll> st;
  deque<ll> dq;

  vector<ll> v(n);

  fori(i,0,n-1)
    cin >> v[i];

  fori(i,0,n-1)
  {
    if (st.empty())
    {
      st.insert(v[i]);
      dq.push_front(v[i]);
    }
    else if (st.find(v[i]) == st.end() && dq.size() == k)
    {
      st.insert(v[i]);
      ll yutu = dq.back();
      st.erase(yutu);
      dq.pop_back();
      dq.push_front(v[i]);
    }
    else if (dq.size() < k)
    {
      st.insert(v[i]);
      dq.push_front(v[i]);
    }
    deque<ll> temp = dq;
    cout << v[i] << " fdf " << endl;
    print(temp);
    // for(auto p : st)
    //   cout << p << " ";
    cout << endl;
  }

  cout << dq.size() << endl;

  while (!dq.empty())
  {
    cout << dq.front() << " ";
    dq.pop_front();
  }

  return 0;
}
