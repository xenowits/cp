#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i < b ; ++i)
#define ford(i,a,b) for(long int i = a;i > b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll cnta=0 ,cntb=0 , res=0;
  fori(i,0,n)
  {
  if(s[i]=='a')
    cnta++;
  else
  cntb++;
  if(i%2==1)
  {
  if(cnta!=cntb)
  {
  res++;
  if(cnta>cntb)
  s[i]='b';
  else
  s[i]='a';
  cnta=(cnta+cntb)/2;
  cntb=cnta;
  }
  }
  }
  cout<<res<<endl;
  if(res==0)
  {
  cout<<s<<endl;
  return 0;
  }
  cout<<s;
  return 0;
}
