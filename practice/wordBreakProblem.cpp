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

map<string,ll> cnt;
string str;

bool solve(int p, int q)
{
  string temp = str.substr(p,q-p+1);
  if (cnt[temp] >= 1)
    return 1;
  bool truth = 0;
  fori(i,p,q-1)
  {
    truth = truth || ( solve(p,i) && solve(i+1,q) );
  }
  return truth;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;

  while (n)
  {
    cin >> str;
    cnt[str] += 1;
    n-=1;
  }

  cin >> str;

  if (solve(0,str.length()-1 ))
    cout << "Yes ha ho skta h";
  else
    cout << "Naah re nhi ho skta";

  return 0;
}
