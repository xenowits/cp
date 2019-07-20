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

string s1, s2, s3;
ll n1,n2,n3;

bool solve(int p, int q, int r)
{
  cout << p << " " << q << " " << r << endl;
  
  if (p >= n1 || q >= n2 || r >= n3)
    return 1;

  if (s1[p] == s2[q] && s1[p] == s3[r])
    return solve(p+1,q,r+1) || solve(p,q+1,r+1) ;

  else if (s1[p] == s3[r])
    return solve(p+1,q,r+1) || solve(p+1,q,r);

  else if (s2[q] == s3[r])
    return solve(p,q+1,r+1) || solve(p,q+1,r);

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s1 >> s2 >> s3;

  n1 = s1.length();
  n2 = s2.length();
  n3 = s3.length();

  vector<bool> seen(26,0);

  fori(i,0,n1-1)
    seen[s1[i]-'a'] = 1;

  fori(i,0,n1-1)
    seen[s2[i]-'a'] = 1;

  string temp;

  fori(i,0,n3-1)
  {
    if (seen[s3[i]-'a'])
      temp.pb(s3[i]);
  }

  s3 = temp;n3 = s3.length();
  cout << "ok" << endl;
  if (solve(0,0,0))
    cout << "Yes interleaved h" << endl;
  else
    cout << "Naah kaha se interleaved hoga re.." << endl;

  return 0;
}
