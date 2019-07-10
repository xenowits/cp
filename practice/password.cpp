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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j])
            j = p[j-1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  ll len = s.length();
  vector<int> p = prefix_function(s);
  // fori(i,0,p.size()-1)
  //   cout << p[i] << " ";
  // cout << endl;
  bool ans = false;ll i,toto;
  if (p[len-1] == 0)
  {
    cout << "Just a legend" << endl;
    return 0;
  }
  // cout << p[len-1] << endl;
  // cout << s.substr(0,p[len-1]) << endl;
  //cout << len << " is the length of the string" << endl;
  for(i = len-2; i >= 0; --i)
  {
      //cout << i << " " << p[i] << " wow " << p[len-1] << endl;
      if (p[i] == p[len-1])
      {
        ans = true;
        // ans_indx = i;ans_indx = i;
        //cout << i << " fdfd "<< endl;
      }
      if (ans)
        break;
  }
  if (ans)
  {
    cout << s.substr(0,p[len-1]) << endl;
    return 0;
  }
  // cout << i << " is indx " << s.substr(0,p[len-1]) << endl;
  //cout << p[p[len-1]-1] << " fa" << endl;
  if (p[p[len-1]-1] == 0)
  {
    cout << "Just a legend" << endl;
    return 0;
  }
  cout << s.substr(0,p[p[len-1]-1]) << endl;
  return 0;
}
