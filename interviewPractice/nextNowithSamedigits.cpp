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
  string s;
  cin >> s;
  ll n = s.length();
  unordered_map<char,int> umap;
  int i;
  for(i = n-1; i >=1 ; --i)
  {
    umap[s[i]-'0'] += 1;
    if (s[i-1] < s[i])
    {
      umap[s[i-1]-'0'] += 1;
      break;
    }
  }
  cout << s.substr(0,i-1);
  int temp = s[i-1]-'0';
  for(int j = temp+1 ; j < 10 ; ++j)
  {
    if (umap[j] > 0)
    {
      cout << j;
      umap[j] -= 1;
      break;
    }
  }
  for(int j = 0 ; j < 10 ; j++)
  {
    if (umap[j] > 0)
    {
      while(umap[j] > 0)
      {
        cout << j;
        umap[j] -= 1;
      }
    }
  }
  return 0;
}
