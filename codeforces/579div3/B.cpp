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

  int n;
  cin >> n;
  ll temp;
  map<ll,ll> mp;
  for(int i = 1; i <= n; ++i)
  {
    cin >> temp;
    mp[temp] += 1;
  }
  vector<ll> triples;
  set<ll, greater<ll> > doubles, singles;
  set<ll> st;

  for(auto x : mp)
  {
    if (x.sc == 1)
      singles.insert(x.fs);
    if (x.sc == 2)
      doubles.insert(x.fs);
    else if (x.sc > 2)
      triples.pb(x.fs);
  }

  for(auto x : triples)
  {
    // if (x == 1 && st.find(2) == st.end())
    //   st.insert(2);
    //cout << x << " s ";
    st.insert(x);
    st.insert(x+1);
    if (x > 1)
      st.insert(x-1);
  }
  cout << st.size() << endl;
  for (auto x : doubles)
  {
    // if (x == 1 && st.find(2) == st.end())
    //   st.insert(2);
    cout << x << " d ";
    int cnt = 0;
    if (st.find(x+1) == st.end())
      st.insert(x+1), cnt+=1;

    if (st.find(x) == st.end())
    {
        st.insert(x);
        cnt += 1;
    }
    if (cnt == 2)
      continue;
    else if (x > 1 && st.find(x-1) == st.end())
      st.insert(x-1);

  }
  for (auto p : st)
    cout << p << " ";
  cout << endl;
  for(auto x : singles)
  {
    cout << x << " s ";
    if (st.find(x+1) == st.end())
      st.insert(x+1);

    else if (st.find(x) == st.end())
    {
        st.insert(x);
    }

    else if (x > 1 && st.find(x-1) == st.end())
      st.insert(x-1);

  }
  cout << endl;
  for(auto p : st)
    cout << p << " ";
  cout << endl;

  cout << st.size() << endl;

  return 0;
}
